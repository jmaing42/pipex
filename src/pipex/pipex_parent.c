/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:54:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 08:24:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "wrap.h"
#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_process.h"

#define BUFFER_SIZE 1024

static t_err	dispose_others(t_pipex *self, char **path)
{
	t_err	error;
	size_t	i;

	error = false;
	i = -1;
	while (++i < self->node_count)
	{
		if (i != 0)
			error |= wrap_close(self->node[i].fd_in);
		error |= wrap_close(self->node[i].fd_out);
	}
	error |= wrap_close(self->last_pipe_in);
	ft_cstring_split_free(path);
	return (error);
}

int	pipex_parent(t_pipex *self, pid_t *pids, char **path)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes;
	bool	in_closed;
	bool	out_closed;

	in_closed = false;
	out_closed = false;
	if (dispose_others(self, path))
		return (EXIT_FAILURE);
	while (!in_closed || !out_closed)
	{
		if (!in_closed)
		{
			bytes = wrap_read(self->in->fd, buffer, BUFFER_SIZE);
			if (bytes < 0 && errno != EAGAIN)
				return (EXIT_FAILURE);
			if (bytes > 0)
				ft_write(self->node[0].fd_in, buffer, bytes);
			if (!bytes && wrap_close(self->node[0].fd_in))
				return (EXIT_FAILURE);
			in_closed = !bytes;
		}
		if (!out_closed)
		{
			bytes = wrap_read(self->last_pipe_out, buffer, BUFFER_SIZE);
			if (bytes < 0 && errno != EAGAIN)
				return (EXIT_FAILURE);
			if (bytes > 0)
				ft_write(self->out->fd, buffer, bytes);
			if (!bytes && wrap_close(self->out->fd))
				return (EXIT_FAILURE);
			out_closed = !bytes;
		}
	}
	return (ft_os_process_wait_pids(pids, self->node_count));
}
