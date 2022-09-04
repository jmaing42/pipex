/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 08:48:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 06:33:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_fork.h"
#include "ft_os_process.h"
#include "ft_os_util_envp.h"

#include "ft_malloc.h"

char	**get_path(void)
{
	const char *const	paths = ft_os_util_envp_get(environ, "PATH");

	if (!paths)
		return (NULL);
	return (ft_nonnull(ft_cstring_split(paths, ":")));
}

int	main(int argc, char **argv)
{
	t_pipex *const	pipex = pipex_init(argc - 1, argv + 1);
	char **const	path = get_path();
	pid_t *const	pids = ft_malloc(sizeof(pid_t) * argc - 3);
	size_t			index;
	size_t			count;

	if (ft_os_fork_multiple(pipex->node_count, pids, &index, &count))
	{
		ft_os_process_wait_pids(pids, count);
		ft_puts(STDOUT_FILENO, "Failed to fork");
		return (EXIT_FAILURE);
	}
	if (index == (size_t)(-1))
		return (pipex_parent(pipex, pids));
	else
		return (pipex_child(pipex, index, path));
}
