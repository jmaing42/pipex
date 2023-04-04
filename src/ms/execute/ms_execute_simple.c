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
#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"
#include "ms_expand.h"

static t_err	find_path(char **path, char *cmd_name, char **out_name)
{
	char	*slash_cmd;
	size_t	index;

	if (ft_cstring_contains_char(cmd_name, '/'))
	{
		if (ft_cstring_duplicate(cmd_name, out_name))
			return (true);
		return (false);
	}
	if (ft_cstring_concat("/", cmd_name, &slash_cmd))
		return (true);
	*out_name = NULL;
	index = -1;
	while (path && path[++index])
	{
		if (ft_cstring_concat(path[index], slash_cmd, out_name))
			return (true);
		if (access(*out_name, F_OK) != FAIL)
			break ;
		free(*out_name);
		*out_name = NULL;
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

t_err	ms_execute_command_simple(
	t_ms_command_simple *command,
	int *piped_input,
	int *piped_output
)
{
	char	**args;
	char	**parsed_path;
	char	*cmd_name;

	if (ms_expand(&command->word_list, &args))
		return (true);
	if (get_parsed_path(&parsed_path))
	{
		ft_cstring_split_free(args);
		return (true);
	}
	if (find_path(parsed_path, args[0], &cmd_name))
	{
		ft_cstring_split_free(parsed_path);
		ft_cstring_split_free(args);
		return (true);
	}
	execve(cmd_name, args, NULL); //test only
	//TO DO: redirection
	// if (find_path(&args[0], &cmd_path))
	(void)piped_input;
	(void)piped_output;
	return (false);
}
