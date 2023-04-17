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

#include "ft_io.h"
#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_types.h"
#include "ms.h"
#include "wrap.h"
#include "ft_memory.h"
#include "ft_os_fork.h"
#include "ft_os_pipe.h"

static void	wait_all(t_ms_execute_cmd_pipe_info *info)
{
	int	status;

	if (info->redirection_in_pid)
	{
		if (wrap_waitpid(info->redirection_in_pid, &status, 0) < 0
			|| WEXITSTATUS(status))
			wrap_exit(EXIT_FAILURE);
	}
	if (info->command_pid)
	{
		wrap_waitpid(info->command_pid, &status, 0);
		ms_execute_globals()->exit_status = WEXITSTATUS(status);
	}
	if (info->redirection_out_pid)
	{
		if (wrap_waitpid(info->redirection_out_pid, &status, 0) < 0
			|| WEXITSTATUS(status))
			wrap_exit(EXIT_FAILURE);
	}
}

static void	in_out_execute(t_ms_command *command, bool is_first, bool is_last)
{
	t_ms_execute_cmd_pipe_info	info;

	ft_memory_set(&info, 0, sizeof(t_ms_execute_cmd_pipe_info));
	info.is_first = true;
	if (ms_execute_check_infiles(command))
		wrap_exit(EXIT_FAILURE);
	if (ms_execute_pipe_and_fork(&info, &info.redirection_in_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.redirection_in_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_redirection_in, is_first, is_last);
	if (ms_execute_pipe_and_fork(&info, &info.command_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.command_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_command, is_first, is_last);
	info.is_last = true;
	if (ms_execute_pipe_and_fork(&info, &info.redirection_out_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.redirection_out_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_redirection_out, is_first, is_last);
	wrap_close(info.previous_pipe_read);
	wait_all(&info);
}

static void	in_execute(t_ms_command *command, bool is_first, bool is_last)
{
	t_ms_execute_cmd_pipe_info	info;

	ft_memory_set(&info, 0, sizeof(t_ms_execute_cmd_pipe_info));
	info.is_first = true;
	if (ms_execute_check_infiles(command))
		wrap_exit(EXIT_FAILURE);
	if (ms_execute_pipe_and_fork(&info, &info.redirection_in_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.redirection_in_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_redirection_in, is_first, is_last);
	wait_all(&info);
	info.is_last = true;
	if (ms_execute_pipe_and_fork(&info, &info.command_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.command_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_command, is_first, is_last);
	wrap_close(info.previous_pipe_read);
	wait_all(&info);
}

static void	out_execute(t_ms_command *command, bool is_first, bool is_last)
{
	t_ms_execute_cmd_pipe_info	info;

	ft_memory_set(&info, 0, sizeof(t_ms_execute_cmd_pipe_info));
	info.is_first = true;
	if (ms_execute_pipe_and_fork(&info, &info.command_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.command_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_command, is_first, is_last);
	info.is_last = true;
	if (ms_execute_pipe_and_fork(&info, &info.redirection_out_pid))
		wrap_exit(EXIT_FAILURE);
	if (info.redirection_out_pid == CHILD_PID)
		ms_execute_child(
			command, ms_execute_child_type_redirection_out, is_first, is_last);
	wrap_close(info.previous_pipe_read);
	wait_all(&info);
}

void	ms_execute_command(t_ms_command *command, bool is_first, bool is_last)
{
	t_ms_redirections_info	info;

	ft_memory_set(&info, 0, sizeof(t_ms_redirections_info));
	if ((command->type == ms_command_type_compound
			&& command->value.compound->redirections.in.head != NULL)
		|| (command->type == ms_command_type_simple
			&& command->value.simple->redirections.in.head != NULL))
		info.have_redirection_in = true;
	if ((command->type == ms_command_type_compound
			&& command->value.compound->redirections.out.head != NULL)
		|| (command->type == ms_command_type_simple
			&& command->value.simple->redirections.out.head != NULL))
		info.have_redirection_out = true;
	if (info.have_redirection_in && info.have_redirection_out)
		in_out_execute(command, is_first, is_last);
	else if (info.have_redirection_in)
		in_execute(command, is_first, is_last);
	else if (info.have_redirection_out)
		out_execute(command, is_first, is_last);
	else
		ms_execute_child(
			command, ms_execute_child_type_command, is_first, is_last);
}
