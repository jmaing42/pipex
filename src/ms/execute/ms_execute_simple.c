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
#include "ft_memory.h"
#include "ft_os_file.h"
#include "ms_builtin.h"
#include "ms_execute.h"

#include <_stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/unistd.h>
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
	const char *const	path = ms_expand_env_get("PATH");

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

static	void	execute_builtin(char **args)
{
	if (ft_cstring_equals(args[0], "cd"))
		ms_builtin_cd(args[1]);
	if (ft_cstring_equals(args[0], "echo"))
		ms_builtin_echo(args);
	if (ft_cstring_equals(args[0], "env"))
		ms_builtin_env();
	if (ft_cstring_equals(args[0], "exit"))
		ms_builtin_exit();
	if (ft_cstring_equals(args[0], "export"))
		ms_builtin_export(args[1]);
	if (ft_cstring_equals(args[0], "pwd"))
		ms_builtin_pwd();
	if (ft_cstring_equals(args[0], "unset"))
		ms_builtin_unset(args[1]);
	if (ft_cstring_equals(args[0], "cd")
		|| ft_cstring_equals(args[0], "echo")
		|| ft_cstring_equals(args[0], "env")
		|| ft_cstring_equals(args[0], "exit")
		|| ft_cstring_equals(args[0], "export")
		|| ft_cstring_equals(args[0], "pwd")
		|| ft_cstring_equals(args[0], "cd"))
		wrap_exit(ms_execute_globals()->exit_status);
}

void	ms_execute_command_simple(
	t_ms_command_simple *command
)
{
	char	**args;
	char	**envp;
	char	**parsed_path;
	char	*cmd_name;

	if (ms_expand(&command->word_list, &args))
		wrap_exit(EXIT_FAILURE);
	execute_builtin(args);
	if (ms_expand_env_get_environ(&envp))
		wrap_exit(EXIT_FAILURE);
	if (get_parsed_path(&parsed_path))
		wrap_exit(EXIT_FAILURE);
	if (find_cmd_path(parsed_path, args[0], &cmd_name))
		wrap_exit(EXIT_FAILURE);
	if (cmd_name == NULL)
		wrap_exit(COMMAND_NOT_FOUND);
	if (execve(cmd_name, args, envp))
		wrap_exit(EXIT_FAILURE);
}
