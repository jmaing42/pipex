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


static void	child_execute_redirection_in(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_redirect_in_out(info))
		wrap_exit(EXIT_FAILURE);
	if (command->type == ms_command_type_simple)
		ms_execute_redirecions_in(&command->value.simple->redirections.in);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirecions_in(&command->value.compound->redirections.in);
	wrap_exit(EXIT_FAILURE);
}

static void	child_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_redirect_in_out(info))
		wrap_exit(EXIT_FAILURE);
	if (command->type == ms_command_type_simple)
		ms_execute_command_simple(command->value.simple);
	else if (command->type == ms_command_type_compound)
		ms_execute_command_compound(command->value.compound);
	wrap_exit(EXIT_FAILURE);
}

static void	child_exectue_redirection_out(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_redirect_in_out(info))
		wrap_exit(EXIT_FAILURE);
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
	if (ms_execute_pipe_and_fork(info, ms_fork_type_redirection_in))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_execute_redirection_in(command, info);
	if (ms_execute_pipe_and_fork(info, ms_fork_type_command))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_execute_command(command, info);
	if (ms_execute_pipe_and_fork(info, ms_fork_type_redirection_out))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_exectue_redirection_out(command, info);
	return (wait_all(info));
}
