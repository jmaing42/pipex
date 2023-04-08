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
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>

#include "ft_types.h"
#include "ms.h"
#include "wrap.h"


static void	child_execute_redirection_in(t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		ms_execute_redirecions_in(&command->value.simple->redirections.in);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirecions_in(&command->value.compound->redirections.in);
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

static void	child_exectue_redirection_out(t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		ms_execute_redirections_out(&command->value.simple->redirections.out);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirections_out(&command->value.compound->redirections.out);
	wrap_exit(EXIT_FAILURE);
}

static t_err	wait_all(t_ms_execute_pipe_info *info)
{
	int	status;

	wrap_waitpid(info->command_pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	wrap_waitpid(info->command_pid, &status, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(status);
	wrap_waitpid(info->command_pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	return (false);
}

t_err	ms_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_pipe_and_fork(info, &info->redirection_in_pid))
		return (true);
	if (info->redirection_in_pid == CHILD_PID)
		child_execute_redirection_in(command);
	if (info->is_first)
		info->is_first = false;
	if (ms_execute_pipe_and_fork(info, &info->command_pid))
		return (true);
	info->command_pid = CHILD_PID; //test only
	if (info->command_pid == CHILD_PID)
		child_execute_command(command);
	if (ms_execute_pipe_and_fork(info, &info->redirection_out_pid))
		return (true);
	if (info->redirection_out_pid == CHILD_PID)
		child_exectue_redirection_out(command);
	return (wait_all(info));
}
