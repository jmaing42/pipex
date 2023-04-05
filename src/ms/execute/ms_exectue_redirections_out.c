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

#include "ft_types.h"
#include "ms_expand.h"
#include "wrap.h"
#include "ft_stringbuilder.h"

static t_err	get_file_contents(char **out_file_contents)
{
	t_stringbuilder	*builder;
	char			buf[READ_BUF_SIZE + 1];
	ssize_t			read_size;
	ssize_t			left_size;

	builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
	read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			return (true);
		buf[READ_BUF_SIZE] = '\0';
		//TODO: read -> stringbuilder_append_string
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
		read_size = wrap_read(fd, buf, READ_BUF_SIZE);
	}
	return (false);
}

static t_err	write_file(int fd, const char *file_contents, ssize_t total_size)
{
	ssize_t	left_size;
	ssize_t	write_size;

	left_size = total_size;
	while (left_size)
	{
		write_size = wrap_write(fd, file_contents, left_size);
		if (write_size < 0)
			return (true);
		left_size -= write_size;
	}
	return (false);
}

t_err	ms_execute_redirections_out(
	t_ms_redirection_list *rd_list,
	t_ms_execute_pipe_info *info
)
{
	t_ms_redirection_list_node	*node;
	int							fd;
	char						*path;

	if (ms_execute_redirections_control_files(info))
		return (true);
	node = rd_list->head;
	while (node)
	{
		if (ms_execute_redirections_word_to_str(node->target, &path))
			return (true);
		fd = wrap_open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0 || copy_file(fd))
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