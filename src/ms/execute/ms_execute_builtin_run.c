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

#include "ms_builtin.h"
#include "ft_cstring.h"
#include "ft_cstring_split.h"

void	ms_execute_builtin_run(t_ms_command *command)
{
	char	**args;

	if (ms_expand(&command->value.simple->word_list, &args))
		ms_execute_exit(EXIT_FAILURE, "minishell");
	if (ft_cstring_equals(args[0], "cd"))
		ms_builtin_cd(args[1]);
	else if (ft_cstring_equals(args[0], "echo"))
		ms_builtin_echo(args);
	else if (ft_cstring_equals(args[0], "env"))
		ms_builtin_env();
	else if (ft_cstring_equals(args[0], "exit"))
		ms_builtin_exit();
	else if (ft_cstring_equals(args[0], "export"))
		ms_builtin_export(args);
	else if (ft_cstring_equals(args[0], "pwd"))
		ms_builtin_pwd();
	else if (ft_cstring_equals(args[0], "unset"))
		ms_builtin_unset(args[1]);
	ft_cstring_split_free(args);
}
