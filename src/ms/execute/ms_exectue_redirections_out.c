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

#include "ft_io.h"
#include "ft_memory.h"
#include "ms.h"
#include "ms_execute.h"

#include <sys/_types/_size_t.h>
#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ms_expand.h"
#include "wrap.h"
#include "ft_stringbuilder.h"
#include "ft_cstring.h"

static t_err	write_to_all_files(
	t_ms_execute_fd_list_node *node,
	char *buf,
	size_t write_size
)
{
	while (node)
	{
		if (ft_write(node->fd, buf, write_size))
			return (true);
		node = node->next;
	}
	return (false);
}

static t_err	add_node(
	t_ms_execute_fd_list *fd_list,
	int fd
)
{
	t_ms_execute_fd_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_execute_fd_list_node));
	new_node->fd = fd;
	if (new_node == NULL)
		return (true);
	if (fd_list->head == NULL)
	{
		fd_list->head = new_node;
		fd_list->tail = new_node;
	}
	else
	{
		fd_list->tail->next = new_node;
		fd_list->tail = fd_list->tail->next;
	}
	return (false);
}

static t_err	init_fd_list(
	t_ms_execute_fd_list *fd_list,
	t_ms_redirection_list_node *node,
	bool is_last
)
{
	char	*path;
	int		fd;

	ft_memory_set(fd_list, 0, sizeof(t_ms_execute_fd_list));
	if (!is_last)
	{
		if (add_node(fd_list, STDOUT_FILENO))
			return (true);
	}
	while (node)
	{
		if (ms_execute_redirections_word_to_str(node->target, &path))
			return (true);
		if (node->is_special)
			fd = wrap_open(path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			fd = wrap_open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0 || add_node(fd_list, fd))
			return (true);
		free(path);
		node = node->next;
	}
	return (false);
}

void	ms_execute_redirections_out(
	t_ms_redirection_list *rd_list,
	bool is_last
)
{
	t_ms_execute_fd_list	fd_list;
	char					buf[READ_BUF_SIZE + 1];
	ssize_t					read_size;

	init_fd_list(&fd_list, rd_list->head, is_last);
	read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			wrap_exit(EXIT_FAILURE);
		buf[READ_BUF_SIZE] = '\0';
		if (write_to_all_files(fd_list.head, buf, read_size))
			wrap_exit(EXIT_FAILURE);
		read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	}
	wrap_exit(EXIT_SUCCESS);
}
