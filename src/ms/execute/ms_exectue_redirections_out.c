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

#include <sys/_types/_size_t.h>
#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

#include "ft_types.h"
#include "ms_expand.h"
#include "wrap.h"
#include "ft_stringbuilder.h"
#include "ft_cstring.h"

static t_err	get_file_contents(char **out_file_contents)
{
	t_stringbuilder	*builder;
	char			buf[READ_BUF_SIZE + 1];
	ssize_t			read_size;

	builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
	if (builder == NULL)
		return (true);
	read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			return (true);
		buf[READ_BUF_SIZE] = '\0';
		if (ft_stringbuilder_append_string(builder, buf))
		{
			ft_stringbuilder_free(builder);
			return (true);
		}
		read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	}
	*out_file_contents = ft_stringbuilder_to_string(builder, 0);
	ft_stringbuilder_free(builder);
	if (*out_file_contents == NULL)
		return (true);
	return (false);
}

static t_err	write_file(int fd, const char *file_contents)
{
	const size_t	file_contents_len = ft_cstring_length(file_contents);
	size_t			left_size;
	ssize_t			write_size;

	left_size = file_contents_len;
	while (left_size)
	{
		write_size = wrap_write(fd, file_contents, left_size);
		if (write_size < 0)
			return (true);
		left_size -= (size_t)write_size;
	}
	return (false);
}

static t_err	internal(
	t_ms_redirection_list_node	*node,
	char *file_contents
)
{
	char	*path;
	int		fd;

	while (node)
	{
		if (ms_execute_redirections_word_to_str(node->target, &path))
			return (true);
		if (node->is_special)
			fd = wrap_open(path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			fd = wrap_open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0 || write_file(fd, file_contents))
		{
			wrap_free(path);
			return (true);
		}
		wrap_free(path);
		node = node->next;
	}
	wrap_close(fd);
	return (write_file(STDOUT_FILENO, file_contents));
}

t_err	ms_execute_redirections_out(
	t_ms_redirection_list *rd_list,
	t_ms_execute_pipe_info *info
)
{
	char	*file_contents;

	if (ms_execute_redirections_control_files(info)
		|| get_file_contents(&file_contents))
		return (true);
	if (internal(rd_list->head, file_contents))
	{
		wrap_free(file_contents);
		return (true);
	}
	wrap_free(file_contents);
	return (false);
}
