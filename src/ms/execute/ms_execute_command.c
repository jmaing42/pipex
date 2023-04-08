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

#include "ft_os_fork.h"
#include "ft_types.h"
#include "ms.h"
#include "wrap.h"

static void	child_execute_redirection_in(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
	{
		if (ms_execute_redirecions_in(
				&command->value.simple->redirections.in, info))
			wrap_exit(EXIT_FAILURE);
	}
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
	{
		if (ms_execute_redirecions_in(
				&command->value.compound->redirections.in, info))
			wrap_exit(EXIT_FAILURE);
	}
	wrap_exit(EXIT_SUCCESS);
}

static void	child_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
	{
		if (ms_execute_command_simple(command->value.simple, info))
			wrap_exit(EXIT_FAILURE);
	}
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
	{
		if (ms_execute_command_compound(command->value.compound, info))
			wrap_exit(EXIT_FAILURE);
	}
	wrap_exit(EXIT_SUCCESS);
}

static void	child_exectue_redirection_out(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
	{
		if (ms_execute_redirections_out(
				&command->value.simple->redirections.out, info))
			wrap_exit(EXIT_FAILURE);
	}
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
	{
		if (ms_execute_redirections_out(
				&command->value.compound->redirections.out, info))
			wrap_exit(EXIT_FAILURE);
	}
	wrap_exit(EXIT_SUCCESS);
}

t_err	ms_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	int	status;

	if (ft_os_fork(&info->pid))
		return (true);
	if (info->pid == CHILD_PID)
		child_execute_redirection_in(command, info);
	wrap_waitpid(info->pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	if (ft_os_fork(&info->pid))
		return (true);
	if (info->pid == CHILD_PID)
		child_execute_command(command, info);
	wrap_waitpid(info->pid, &status, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(status);
	if (ft_os_fork(&info->pid))
		return (true);
	if (info->pid == CHILD_PID)
		child_exectue_redirection_out(command, info);
	wrap_waitpid(info->pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	return (false);
}
