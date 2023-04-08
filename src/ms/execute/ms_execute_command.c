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

#include "ft_os_pipe.h"
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
	if (ms_execute_redirect_in_out(info))
		wrap_exit(EXIT_FAILURE);
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		ms_execute_redirecions_in(&command->value.simple->redirections.in);
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
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
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		ms_execute_command_simple(command->value.simple);
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
		ms_execute_command_compound(command->value.compound, info);
	wrap_exit(EXIT_FAILURE);
}

static void	child_exectue_redirection_out(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	if (ms_execute_redirect_in_out(info))
		wrap_exit(EXIT_FAILURE);
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		ms_execute_redirections_out(&command->value.simple->redirections.out);
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
		ms_execute_redirections_out(&command->value.compound->redirections.out);
	wrap_exit(EXIT_FAILURE);
}

static pid_t	do_fork(
	t_ms_execute_pipe_info *info,
	t_ms_execute_pid_type type
)
{
	if (type == MS_FORK_TYPE_REDIRECTION_IN)
		return (ft_os_fork(&info->redirection_in_pid));
	else if (type == ms_fork_type_command)
		return (ft_os_fork(&info->command_pid));
	else if (type == ms_fork_type_redirection_out)
		return (ft_os_fork(&info->redirection_out_pid));
	return (FAIL);
}

static t_err	pipe_and_fork(
	t_ms_execute_pipe_info *info,
	t_ms_execute_pid_type type
)
{
	pid_t	pid;

	if (!info->is_first)
		info->previous_pipe_read = info->pipe_read;
	if (ft_os_pipe(&info->pipe_write, &info->pipe_read))
		return (true);
	pid = do_fork(info, type);
	if (pid == FAIL)
		return (true);
	if (pid == CHILD_PID)
	{
		if (ms_execute_redirect_in_out(info))
			wrap_exit(EXIT_FAILURE);
	}
	else
	{
		if (info->is_first)
			info->is_first = false;
		else
			wrap_close(info->previous_pipe_read);
		wrap_close(info->pipe_read);
		wrap_close(info->pipe_write);
	}
	return (false);
}

t_err	ms_execute_command(
	t_ms_command *command,
	t_ms_execute_pipe_info *info
)
{
	int	status;

	if (pipe_and_fork(info))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_execute_redirection_in(command, info);
	wrap_waitpid(info->command_pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	if (pipe_and_fork(info))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_execute_command(command, info);
	wrap_waitpid(info->command_pid, &status, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(status);
	if (ft_os_fork(&info->command_pid))
		return (true);
	if (info->command_pid == CHILD_PID)
		child_exectue_redirection_out(command, info);
	wrap_waitpid(info->command_pid, &status, 0);
	if (WEXITSTATUS(status))
		return (true);
	return (false);
}
