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
#include <sys/wait.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_os_fork.h"
#include "ft_exit.h"
#include "ms.h"

static t_err setup_redirections(t_ms_command_compound *command)
{
	// TODO: set up redirections
	return ((void)command, true);
}

t_err	ms_execute_command_compound(t_ms_command_compound *command)
{
	pid_t	pid;
	int		stat;

	if (ft_os_fork(&pid))
		return (true);
	if (pid == 0)
	{
		if (setup_redirections(command)
			|| ms_execute_and_or_list(&command->and_or_list))
			ft_exit(EXIT_FAILURE);
		ft_exit(ms_execute_globals()->exit_status);
	}
	wrap_waitpid(pid, &stat, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(stat);
	return (false);
}
