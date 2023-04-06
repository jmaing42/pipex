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

static t_err	command_simple(
	t_ms_command_simple *simple,
	t_ms_execute_pipe_info *info
)
{
	int		status;
	pid_t	pid;

	if (ft_os_fork(&pid))
		return (true);
	if (pid == CHILD_PID)
	{
		if (ms_execute_redirecion_in(&simple->redirections.in, info))
			wrap_exit(EXIT_FAILURE);
	}
	wrap_waitpid(pid, &status, 0);
	if (status != )
		wrap_exit(EXIT_FAILURE);
	if (ms_execute_command_simple(simple, info))
		wrap_exit(EXIT_FAILURE);
	
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
	{
		if (command->type == MS_COMMAND_TYPE_SIMPLE)
		{
			if (command_simple(command->value.simple, info))
				return (true);
		}
		else if (command->type == MS_COMMAND_TYPE_COMPOUND)
		{
			if (command_compound(command->value.compound, info))
				return (true);
		}
	}
	wrap_waitpid(info->pid, &status, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(status);
	return (false);
}
