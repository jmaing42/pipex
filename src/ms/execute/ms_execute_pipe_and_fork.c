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

#include "ft_os_pipe.h"
#include "ft_os_fork.h"
#include "wrap.h"

static pid_t	do_fork(
	t_ms_execute_pipe_info *info,
	t_ms_execute_pid_type type
)
{
	if (type == ms_fork_type_redirection_in)
		return (ft_os_fork(&info->redirection_in_pid));
	else if (type == ms_fork_type_command)
		return (ft_os_fork(&info->command_pid));
	else if (type == ms_fork_type_redirection_out)
		return (ft_os_fork(&info->redirection_out_pid));
	return (FAIL);
}

t_err	ms_execute_pipe_and_fork(
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
