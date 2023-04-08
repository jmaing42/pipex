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

#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "ft_exit.h"
#include "ft_os_file.h"
#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"
#include "ms_expand.h"
#include "wrap.h"
#include "ft_os_fork.h"

static t_err	check_path(char **path, char *slash_cmd, char **out_name)
{
	size_t	index;

	*out_name = NULL;
	index = -1;
	while (path && path[++index])
	{
		if (ft_cstring_concat(path[index], slash_cmd, out_name))
			return (true);
		if (ft_os_file_is_executable((const char *)*out_name))
			break ;
		free(*out_name);
		*out_name = NULL;
	}
	return (false);
}

static t_err	find_cmd_path(char **path, char *cmd_name, char **out_name)
{
	char	*slash_cmd;

	if (ft_cstring_contains_char(cmd_name, '/'))
	{
		if (ft_cstring_duplicate(cmd_name, out_name))
			return (true);
		return (false);
	}
	if (ft_cstring_concat("/", cmd_name, &slash_cmd))
		return (true);
	if (check_path(path, slash_cmd, out_name))
	{
		free(slash_cmd);
		return (true);
	}
	free(slash_cmd);
	return (false);
}

static t_err	get_parsed_path(char ***out_parsed_path)
{
	const char	*path = ms_expand_env_get("PATH");

	if (path == NULL)
	{
		*out_parsed_path = NULL;
		return (false);
	}
	*out_parsed_path = ft_cstring_split(path, ":");
	if (*out_parsed_path == NULL)
		return (true);
	return (false);
}

void	ms_execute_command_simple(
	t_ms_command_simple *command
)
{
	char	**args;
	char	**parsed_path;
	char	*cmd_name;
	int		stat;

	if (ms_expand(&command->word_list, &args))
		wrap_exit(EXIT_FAILURE);
	if (get_parsed_path(&parsed_path))
		wrap_exit(EXIT_FAILURE);
	if (find_cmd_path(parsed_path, args[0], &cmd_name))
		wrap_exit(EXIT_FAILURE);
	if (execve(cmd_name, args, NULL))
		wrap_exit(EXIT_FAILURE);
	ms_execute_globals()->exit_status = WEXITSTATUS(stat);
	wrap_exit(ms_execute_globals()->exit_status);
}
