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
	t_ms_redirection_list_node *node,
	char *buf,
	size_t write_size
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
		if (fd < 0 || ft_write(fd, buf, write_size))
		{
			wrap_free(path);
			return (true);
		}
		wrap_free(path);
		node = node->next;
	}
	wrap_close(fd);
	return (false);
}

void	ms_execute_redirections_out(t_ms_redirection_list *rd_list)
{
	char			buf[READ_BUF_SIZE + 1];
	ssize_t			read_size;

	read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			wrap_exit(EXIT_FAILURE);
		buf[READ_BUF_SIZE] = '\0';
		if (write_to_all_files(rd_list->head, buf, read_size))
			wrap_exit(EXIT_FAILURE);
		read_size = wrap_read(STDIN_FILENO, buf, READ_BUF_SIZE);
	}
	wrap_exit(EXIT_SUCCESS);
}
