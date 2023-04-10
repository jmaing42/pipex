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

#include "ft_os_fork.h"
#include "ft_os_pipe.h"
#include "ms_execute.h"

#include <stdlib.h>
#include <stdbool.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>

#include "ft_types.h"
#include "ms.h"
#include "wrap.h"

#include <stdio.h> //test only
#include <unistd.h>

static void	child_execute_redirection_in(t_ms_command *command)
{
	if (command->type == ms_command_type_simple)
		ms_execute_redirecions_in(
			&command->value.simple->redirections.in);
	else if (command->type == ms_command_type_compound)
		ms_execute_redirecions_in(
			&command->value.compound->redirections.in);
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

static t_err	wait_all(t_ms_execute_pipe_info *info, t_err result)
{
	int	status;

	if (info->redirection_in_pid)
	{
		wrap_waitpid(info->redirection_in_pid, &status, 0);
		if (WEXITSTATUS(status))
			return (true);
	}
	if (info->command_pid)
	{
		wrap_waitpid(info->command_pid, &status, 0);
		ms_execute_globals()->exit_status = WEXITSTATUS(status);
	}
	if (info->redirection_out_pid)
	{
		wrap_waitpid(info->redirection_out_pid, &status, 0);
		if (WEXITSTATUS(status))
			return (true);
	}
	return (result);
}

t_err	ms_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_pipe_and_fork(info, &info->redirection_in_pid))
		return (wait_all(info, true));
	if (info->redirection_in_pid == CHILD_PID)
	{
		printf("@@@@@@red_in@@@@@@@\n");
		child_execute_redirection_in(command);
	}
	if (ms_execute_pipe_and_fork(info, &info->command_pid))
		return (wait_all(info, true));
	if (info->command_pid == CHILD_PID)
	{
		printf("@@@@@@command@@@@@@@\n");
		child_execute_command(command);
	}
	// info->command_pid = CHILD_PID; //test only
	if (ms_execute_pipe_and_fork(info, &info->redirection_out_pid))
		return (wait_all(info, true));
	if (info->redirection_out_pid == CHILD_PID)
	{
		printf("@@@@@@red_out@@@@@@@\n");
		child_exectue_redirection_out(command);
	}
	wrap_close(info->pipe_read);
	return (wait_all(info, false));
}
