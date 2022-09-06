/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:54:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/06 23:31:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_os_file.h"
#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "wrap.h"

#include <stdio.h>

int	pipex_child(
	t_pipex *self,
	pid_t *pids,
	size_t index,
	const char *const *path
)
{
	const t_pipex_node	*it = &self->node[index];
	char				*executable_path;
	size_t				i;

	(void)pids;
	i = -1;
	while (++i < self->node_count)
	{
		if (i == index)
			continue ;
		wrap_close(self->node[i].fd_in);
		wrap_close(self->node[i].fd_out);
	}
	if (ft_os_file_resolve_executable_path(it->args[0], path, &executable_path))
		return (EXIT_FAILURE);
	if (!executable_path)
	{
		ft_write(STDERR_FILENO, "command not found\n", 18);
		return (EXIT_FAILURE);
	}
	return ((index != 0
			&& wrap_dup2(self->node[index].fd_in, STDIN_FILENO) == -1)
		|| (index != self->node_count - 1
			&& wrap_dup2(STDOUT_FILENO, self->node[index + 1].fd_out) == -1)
		|| execve(executable_path, it->args, it->envp) == -1);
}
