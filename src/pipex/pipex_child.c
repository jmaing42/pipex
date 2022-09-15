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

#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "wrap.h"
#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_file.h"

t_err	dispose_others(t_pipex *self, pid_t *pids, size_t index, char **path)
{
	t_err	error;
	size_t	i;

	error = false;
	i = 0;
	while (++i < self->node_count)
	{
		error |= (i != index && wrap_close(self->node[i].fd_out));
		error |= (i != index + 1 && wrap_close(self->node[i].fd_in));
	}
	error |= wrap_close(self->in->fd);
	error |= (index != self->node_count - 1 && wrap_close(self->out->fd));
	free(pids);
	ft_cstring_split_free(path);
	return (error);
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
	if (dispose_others(self, pids, index, path))
		return (EXIT_FAILURE);
	if (!executable_path)
	{
		ft_write(STDERR_FILENO, "command not found\n", 18);
		return (EXIT_FAILURE);
	}
	return (
		wrap_dup2(self->node[index].fd_out, STDIN_FILENO) < 0
		|| (index != self->node_count - 1
			&& wrap_dup2(self->node[index + 1].fd_in, STDOUT_FILENO) < 0)
		|| (index == self->node_count - 1
			&& wrap_dup2(self->out->fd, STDOUT_FILENO) < 0)
		|| execve(executable_path, it->args, it->envp) < 0);
}
