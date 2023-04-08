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

#include "ms.h"
#include "test.h"

#include <stdio.h>

static t_err	print_command_simple(t_ms_command_simple *command_simple)
{
	if (print_word_list(&command_simple->word_list))
		return (true);
	return (false);
}

static t_err	print_command_compound(t_ms_command_compound *command_compound)
{
	if (print_and_or_list(&command_compound->and_or_list))
		return (true);
	return (false);
}

t_err	print_command(t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		return (print_command_simple(command->value.simple));
	if (command->type == ms_command_type_compound)
		return (print_command_compound(command->value.compound));
	return (true);
}
