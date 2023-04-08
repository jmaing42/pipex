/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_redirect_in_out.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/08 14:53:58 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"
#include "wrap.h"

t_err	ms_execute_redirect_in_out(t_ms_execute_pipe_info *info)
{
	if (!info->is_first)
	{
		if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO))
			return (true);
		wrap_close(info->previous_pipe_read);
	}
	if (wrap_dup2(info->pipe_write, STDOUT_FILENO))
		return (true);
	wrap_close(info->pipe_read);
	wrap_close(info->pipe_write);
	return (false);
}
