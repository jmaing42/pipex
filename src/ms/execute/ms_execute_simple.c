/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:23:21 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/31 16:56:21 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"

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
	index = 0;
	while (path && path[index])
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

static t_err	parse_path(char *path, char **out_parsed_path)
{
	
}

t_err	ms_execute_command_simple(
	t_ms_command_simple *command,
	int *piped_input,
	int *piped_output
)
{
	char	**args;
	char	*cmd_path;

	if (ms_expand(&command->word_list, &args))
		return (true);
	//TO DO: redirection
	if (find_path(, args[0], &cmd_path))
	return (false);
}
