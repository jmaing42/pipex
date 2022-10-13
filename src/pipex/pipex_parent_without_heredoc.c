/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent_without_parent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/10/13 10:30:38 by Juyeong Maing    ###   ########.fr       */
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
		error |= wrap_close(self->node[i].fd_in);
		error |= wrap_close(self->node[i].fd_out);
	}
	ft_cstring_split_free(path);
	return (error);
}

int	pipex_parent_without_heredoc(t_pipex *self, pid_t *pids, char **path)
{
	if (dispose_others(self, path))
		return (EXIT_FAILURE);
	return (ft_os_process_wait_pids(pids, self->node_count));
}
