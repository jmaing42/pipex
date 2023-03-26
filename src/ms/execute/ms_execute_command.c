/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:18:51 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/23 21:30:12 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdlib.h>
#include <stdbool.h>

#include "ft_types.h"
#include "ms.h"

t_err	ms_execute_command(
	t_ms_command *command,
	int *piped_input,
	int *piped_output
)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		return (ms_execute_command_simple(command->value.simple,
				piped_input, piped_output));
	if (command->type == MS_COMMAND_TYPE_COMPOUND)
		return (ms_execute_command_compound(command->value.compound,
				piped_input, piped_output));
	return (true);
}
