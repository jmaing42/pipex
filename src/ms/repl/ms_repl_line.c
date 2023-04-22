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

#include "ms_repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "ms.h"
#include "ft_io.h"
#include "wrap.h"
#include "ft_memory.h"
#include "ft_types_char.h"
#include "ft_cstring.h"
#include "ms_execute.h"

static bool	is_empty_str(char *line)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (!ft_types_char_space(line[index]))
			return (false);
		++index;
	}
	return (true);
}

static void	free_and_unlink_string_list(t_ms_repl_string_list *list)
{
	t_ms_repl_string_list_node	*node;
	t_ms_repl_string_list_node	*next_node;

	node = list->head;
	while (node)
	{
		next_node = node->next;
		wrap_unlink(node->str);
		free(node->str);
		free(node);
		node = next_node;
	}
}

static t_err	execute_program(t_ms_program *program)
{
	t_ms_repl_string_list	tmp_files;

	ft_memory_set(&tmp_files, 0, sizeof(tmp_files));
	if (ms_repl_heredoc_parse(program, &tmp_files))
	{
		free_and_unlink_string_list(&tmp_files);
		return (true);
	}
	if (ms_execute(program))
	{
		free_and_unlink_string_list(&tmp_files);
		return (true);
	}
	free_and_unlink_string_list(&tmp_files);
	return (false);
}

static void	eof_handler(void)
{
	if (ft_puts(STDOUT_FILENO, "exit"))
		ms_repl_die();
	wrap_exit(EXIT_SUCCESS);
}

void	ms_repl_line(void)
{
	t_ms_program	*program;
	char			*line;

	line = readline("minishell> ");
	if (line == GET_EOF)
		eof_handler();
	if (is_empty_str(line))
	{
		free(line);
		return ;
	}
	add_history(line);
	if (ms_parse(line, &program))
		ms_repl_die();
	if (!program)
	{
		ft_puts(STDERR_FILENO, "syntax error\n");
		return ;
	}
	if (execute_program(program))
		ms_repl_die();
	wrap_free(line);
}
