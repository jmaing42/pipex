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

#include "ms_execute.h"

#include <stdlib.h>

#include "ms.h"
#include "wrap.h"
#include "ft_cstring.h"

static bool	is_builtin(char *cmd_name)
{
	if (ft_cstring_equals(cmd_name, "cd"))
		return (true);
	if (ft_cstring_equals(cmd_name, "echo"))
		return (true);
	if (ft_cstring_equals(cmd_name, "env"))
		return (true);
	if (ft_cstring_equals(cmd_name, "exit"))
		return (true);
	if (ft_cstring_equals(cmd_name, "export"))
		return (true);
	if (ft_cstring_equals(cmd_name, "pwd"))
		return (true);
	if (ft_cstring_equals(cmd_name, "unset"))
		return (true);
	return (false);
}

bool	ms_execute_builtin_check(t_ms_pipe_list *list)
{
	char	*cmd_name;

	if (list->head != list->tail)
		return (false);
	if (list->head->command.type == ms_command_type_compound)
		return (false);
	if (ms_execute_word_to_str(
			list->head->command.value.simple->word_list.head->word
			, &cmd_name))
		ms_execute_exit(EXIT_FAILURE, "minishell");
	if (is_builtin(cmd_name))
	{
		wrap_free(cmd_name);
		return (true);
	}
	wrap_free(cmd_name);
	return (false);
}
