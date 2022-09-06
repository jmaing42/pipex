/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:54:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 05:25:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "wrap.h"
#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_file.h"

void	dispose_others(t_pipex *self, pid_t *pids, size_t index, char **path)
{
	size_t	i;

	i = -1;
	while (++i < self->node_count)
	{
		if (i != index)
			wrap_close(self->node[i].fd_in);
		if (i != index - 1)
			wrap_close(self->node[i].fd_out);
	}
	free(pids);
	ft_cstring_split_free(path);
}

int	pipex_child(
	t_pipex *self,
	pid_t *pids,
	size_t index,
	char **path
)
{
	const t_pipex_node	*it = &self->node[index];
	char				*executable_path;

	if (ft_os_file_resolve_executable_path(
			it->args[0], (const char *const *)path, &executable_path))
		return (EXIT_FAILURE);
	dispose_others(self, pids, index, path);
	if (!executable_path)
	{
		ft_write(STDERR_FILENO, "command not found\n", 18);
		return (EXIT_FAILURE);
	}
	return (wrap_dup2(self->node[index].fd_out, STDIN_FILENO) == -1
		|| (index != self->node_count - 1
			&& wrap_dup2(self->node[index + 1].fd_in, STDOUT_FILENO) == -1)
		|| (index == self->node_count - 1
			&& wrap_dup2(self->last_pipe_in, STDOUT_FILENO) == -1)
		|| execve(executable_path, it->args, it->envp) == -1);
}
