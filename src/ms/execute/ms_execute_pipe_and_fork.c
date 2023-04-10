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
#include <sys/_types/_pid_t.h>
#include <unistd.h>

#include "ft_os_pipe.h"
#include "ft_os_fork.h"
#include "wrap.h"

t_err	ms_execute_pipe_and_fork(
	t_ms_execute_pipe_info *info,
	pid_t *out_pid
)
{
	if (ft_os_pipe(&info->pipe_write, &info->pipe_read))
		return (true);
	if (ft_os_fork(out_pid))
		return (true);
	if (*out_pid == CHILD_PID)
	{
		if (ms_execute_redirect_in_out(info))
			wrap_exit(EXIT_FAILURE);
		return (false);
	}
	if (!info->is_first)
		wrap_close(info->previous_pipe_read);
	info->previous_pipe_read = wrap_dup(info->pipe_read);
	if (info->previous_pipe_read < 0)
		return (true);
	wrap_close(info->pipe_write);
	if (info->is_first)
		info->is_first = false;
	return (false);
}
