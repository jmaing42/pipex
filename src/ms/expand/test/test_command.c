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

static t_err	test_command_simple(t_ms_command_simple *command_simple)
{
	if (test_word_list(&command_simple->word_list))
		return (true);
	return (false);
}

static t_err	test_command_compound(t_ms_command_compound *command_compound)
{
	if (test_and_or_list(&command_compound->and_or_list))
		return (true);
	return (false);
}

t_err	test_command(t_ms_command *command)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		return (test_command_simple(command->value.simple));
	if (command->type == MS_COMMAND_TYPE_COMPOUND)
		return (test_command_compound(command->value.compound));
	return (true);
}