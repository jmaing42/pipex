/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:54:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 00:35:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

#include "wrap.h"
#include "ft_cstring_split.h"
#include "ft_os_process.h"

int	pipex_parent(t_pipex *self, pid_t *pids, char **path)
{
	size_t	i;

	i = -1;
	while (++i < self->node_count)
	{
		if (i != 0)
			wrap_close(self->node[i].fd_out);
		if (i != self->node_count - 1)
			wrap_close(self->node[self->node_count - 1].fd_in);
	}
	ft_cstring_split_free(path);
	if (
		wrap_dup2(self->in->fd, self->node[0].fd_in) == -1
		|| wrap_dup2(self->last_pipe_out, self->out->fd) == -1
	)
		return (EXIT_FAILURE);
	ft_os_process_wait_pids(pids, self->node_count);
	return (EXIT_SUCCESS);
}
