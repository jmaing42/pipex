/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 08:48:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 01:21:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_os_fork.h"
#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring_split.h"
#include "ft_os_util_envp.h"

#include "ft_malloc.h"

int	main(int argc, char **argv)
{
	t_pipex *const	pipex = pipex_init(argc - 1, argv + 1);
	char **const	path = ft_nonnull(ft_cstring_split(
				ft_nonnull((void *)ft_os_util_envp_get(environ, "PATH")), ":"));
	pid_t *const	pids = ft_malloc(sizeof(pid_t) * argc - 3);
	size_t			index;
	int				result;

	ft_os_fork_multiple(pipex->node_count, pids, &index);
	if (index == (size_t)(-1))
		result = pipex_parent(pipex, pids);
	else
		result = pipex_child(pipex, index, path);
	return (result);
}
