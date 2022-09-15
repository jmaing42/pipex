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

#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_fork.h"
#include "ft_os_process.h"
#include "ft_os_util_envp.h"

#include "ft_malloc.h"

static char	**get_path(void)
{
	const char *const	paths = ft_os_util_envp_get(environ, "PATH");

	if (!paths)
		return (NULL);
	return (ft_nonnull(ft_cstring_split(paths, ":")));
}

static bool	is_heredoc(int argc, char **argv)
{
	return (argc >= 2 && ft_cstring_equals(argv[1], "here_doc"));
}

static int	main_with_heredoc(t_pipex *pipex, size_t process_count)
{
	char **const	path = get_path();
	pid_t *const	pids = ft_malloc(sizeof(pid_t) * process_count);
	size_t			index;
	size_t			count;

	if (ft_os_fork_multiple(pipex->node_count, pids, &index, &count))
	{
		ft_os_process_wait_pids(pids, count);
		ft_puts(STDOUT_FILENO, "Failed to fork");
		return (EXIT_FAILURE);
	}
	if (index == (size_t)(-1))
		return (pipex_parent_with_heredoc(pipex, pids, path));
	else
		return (pipex_child(pipex, pids, index, path));
}

static int	main_without_heredoc(t_pipex *pipex, size_t process_count)
{
	char **const	path = get_path();
	pid_t *const	pids = ft_malloc(sizeof(pid_t) * process_count);
	size_t			index;
	size_t			count;

	if (ft_os_fork_multiple(pipex->node_count, pids, &index, &count))
	{
		ft_os_process_wait_pids(pids, count);
		ft_puts(STDOUT_FILENO, "Failed to fork");
		return (EXIT_FAILURE);
	}
	if (index == (size_t)(-1))
		return (pipex_parent_without_heredoc(pipex, pids, path));
	else
		return (pipex_child(pipex, pids, index, path));
}

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	if (is_heredoc(argc, argv))
	{
		pipex = pipex_init_with_heredoc(argc - 1, argv + 1);
		if (!pipex)
			return (EXIT_FAILURE);
		return (main_with_heredoc(pipex, argc - 4));
	}
	else
	{
		pipex = pipex_init_without_heredoc(argc - 1, argv + 1);
		if (!pipex)
			return (EXIT_FAILURE);
		return (main_without_heredoc(pipex, argc - 3));
	}
}
