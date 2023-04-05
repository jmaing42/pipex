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

#include "ms_execute.h"

#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

#include "ms.h"
#include "ft_os_file.h"
#include "ms_parse.h"
#include "wrap.h"
#include "ft_memory.h"
#include "ft_types.h"

static t_err	get_word_str(t_ms_word *word, char **out_path)
{
	t_ms_word_list		list;
	t_ms_word_list_node	*node;
	char				**args;

	node = ft_memory_allocate(1, sizeof(t_ms_word_list_node));
	if (node == NULL)
		return (true);
	node->word = word;
	list.head = node;
	list.tail = node;
	if (ms_expand(&list, &args))
	{
		wrap_free(node);
		return (true);
	}
	*out_path = args[0];
	wrap_free(node);
	wrap_free(args);
	return (false);
}

static t_err	control_files(t_ms_execute_pipe_info *info)
{
	if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO))
		return (true);
	if (wrap_dup2(info->pipe_write, STDOUT_FILENO))
		return (true);
	wrap_close(info->previous_pipe_read);
	wrap_close(info->pipe_read);
	wrap_close(info->pipe_write);
	return (false);
}

static t_err	write_file(int fd)
{
	char	buf[WRITE_FILE_BUF_SIZE];
	ssize_t	read_size;
	ssize_t	left_size;
	ssize_t	write_size;

	read_size = wrap_read(fd, buf, WRITE_FILE_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			return (true);
		write_size = wrap_write(STDOUT_FILENO, buf, read_size);
		if (write_size < 0)
			return (true);
		left_size = read_size - write_size;
		while (left_size)
		{
			write_size = wrap_write(STDOUT_FILENO, buf, read_size);
			if (write_size < 0)
				return (true);
			left_size -= write_size;
		}
		read_size = wrap_read(fd, buf, WRITE_FILE_BUF_SIZE);
	}
	return (false);
}

t_err	ms_execute_redirecion_in(
	t_ms_redirection_list *rd_list,
	t_ms_execute_pipe_info *info
)
{
	t_ms_redirection_list_node	*node;
	int							fd;
	char						*path;

	if (control_files(info))
		return (true);
	node = rd_list->head;
	while (node)
	{
		if (get_word_str(node->target, &path))
			return (true);
		fd = wrap_open(path, O_RDONLY);
		if (fd < 0 || write_file(fd))
		{
			wrap_free(path);
			return (true);
		}
		node = node->next;
	}
	wrap_free(path);
	wrap_close(fd);
	return (false);
}
