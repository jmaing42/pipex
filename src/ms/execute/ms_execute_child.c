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

#include <stdio.h>
#include <stdlib.h>

#include "ms.h"
#include "wrap.h"

static void	child_execute_redirection_in(t_ms_command *command, bool is_first)
{
	if (command->type == ms_command_type_simple)
		ms_execute_redirecions_in(
			&command->value.simple->redirections.in, is_first);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirecions_in(
			&command->value.compound->redirections.in, is_first);
	wrap_exit(EXIT_FAILURE);
}

static void	child_execute_command(t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		ms_execute_command_simple(command->value.simple);
	else if (command->type == ms_command_type_compound)
		ms_execute_command_compound(command->value.compound);
	wrap_exit(EXIT_FAILURE);
}

static void	child_execute_redirection_out(t_ms_command *command, bool is_last)
{
	if (command->type == ms_command_type_simple)
		ms_execute_redirections_out(
			&command->value.simple->redirections.out, is_last);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirections_out(
			&command->value.compound->redirections.out, is_last);
	wrap_exit(EXIT_FAILURE);
}

void	ms_execute_child(
	t_ms_command *command,
	t_ms_execute_child_type type,
	bool is_first,
	bool is_last
)
{
	if (type == ms_execute_child_type_redirection_in)
		child_execute_redirection_in(command, is_first);
	else if (type == ms_execute_child_type_command)
		child_execute_command(command);
	else if (type == ms_execute_child_type_redirection_out)
		child_execute_redirection_out(command, is_last);
	wrap_exit(EXIT_FAILURE);
}
