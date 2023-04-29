/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ms_execute.h"
#include "ms_parse.h"
#include "ms_repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <readline/readline.h>
#include <sys/wait.h>

#include "ft_cstring.h"
#include "ft_io.h"
#include "ft_memory.h"
#include "ms.h"
#include "wrap.h"

static t_err	add_part_list_node(t_ms_word_part_list *list, char *file_name)
{
	t_ms_word_part_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_word_part_list_node));
	if (new_node == NULL)
		return (false);
	new_node->type = ms_word_part_single_quoted;
	new_node->value.single_quoted = file_name;
	list->head = new_node;
	list->tail = new_node;
	return (false);
}

static t_err	modify_node(t_ms_redirection_list_node *node, char *file_name)
{
	char	*dup_name;

	if (ft_cstring_duplicate(file_name, &dup_name))
		return (true);
	ms_parse_free_word_part_list(&node->target->part_list);
	if (add_part_list_node(&node->target->part_list, dup_name))
		return (true);
	return (false);
}

static t_err	write_heredoc(int fd, char *limiter)
{
	char	*line;

	line = readline("heredoc> ");
	if (line == NULL)
		return (false);
	while (!ft_cstring_equals(line, limiter))
	{
		if (ft_puts(fd, line) || ft_puts(fd, "\n"))
			return (true);
		wrap_free(line);
		line = readline("heredoc> ");
		if (line == NULL)
			return (false);
	}
	wrap_free(line);
	return (false);
}

static	void	wait_child(pid_t pid)
{
	int	stat;

	wrap_waitpid(pid, &stat, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(stat);
	if (WIFSIGNALED(stat))
		ms_execute_globals()->exit_status = 128 + WTERMSIG(stat);
}

t_err	ms_repl_heredoc_make_tmpfile(
	t_ms_redirection_list_node *node,
	char *file_name,
	char *limiter
)
{
	const pid_t	pid = wrap_fork();
	int			fd;

	ms_repl_heredoc_signals(pid);
	if (pid == CHILD_PID)
	{
		fd = wrap_open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0)
			return (true);
		if (write_heredoc(fd, limiter))
			wrap_exit(EXIT_FAILURE);
		wrap_close(fd);
		wrap_exit(EXIT_SUCCESS);
	}
	wait_child(pid);
	if (modify_node(node, file_name))
		return (true);
	return (false);
}
