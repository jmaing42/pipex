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
#include <stdbool.h>

#include "ft_types.h"
#include "ms.h"

t_err	ms_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		return (ms_execute_command_simple(command->value.simple));
	if (command->type == MS_COMMAND_TYPE_COMPOUND)
		return (ms_execute_command_compound(command->value.compound));
	return (true);
}
