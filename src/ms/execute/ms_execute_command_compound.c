/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command_compound.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/24 22:34:29 by seonlim          ###   ########.fr       */
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

t_err	ms_execute_command_compound(
	t_ms_command_compound *command,
	int *piped_input,
	int *piped_output
)
{
	pid_t	pid;
	int		stat;

	ms_execute_and_or_list(&command->and_or_list);
	if (ft_os_fork(&pid))
		return (true);
	if (pid == 0)
	{
		if (ms_execute_redirections(
				&command->redirections, piped_input, piped_output)
			|| ms_execute_and_or_list(&command->and_or_list))
			ft_exit(EXIT_FAILURE);
		ft_exit(ms_execute_globals()->exit_status);
	}
	wrap_waitpid(pid, &stat, 0);
	ms_execute_globals()->exit_status = WEXITSTATUS(stat);
	return (false);
}
