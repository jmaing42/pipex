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

static t_err	print_command_simple(
	int depth,
	t_ms_command_simple *command_simple
)
{
	if (printf("%*sSimpleCommand {\n", depth, "") < 0)
		return (true);
	if (print_word_list(depth + 1, &command_simple->word_list))
		return (true);
	if (print_redirections(depth + 1, &command_simple->redirections))
		return (true);
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}

static t_err	print_command_compound(
	int depth,
	t_ms_command_compound *command_compound
)
{
	if (printf("%*sCompoundCommand {\n", depth, "") < 0)
		return (true);
	if (print_and_or_list(depth + 1, &command_compound->and_or_list))
		return (true);
	if (print_redirections(depth + 1, &command_compound->redirections))
		return (true);
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}

t_err	print_command(int depth, t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		return (print_command_simple(depth, command->value.simple));
	if (command->type == ms_command_type_compound)
		return (print_command_compound(depth, command->value.compound));
	return (true);
}
