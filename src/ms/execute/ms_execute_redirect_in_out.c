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
#include "wrap.h"

t_err	ms_execute_redirect_in_out(t_ms_execute_pipe_info *info)
{
	if (!info->is_first)
	{
		if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO) < 0)
			return (true);
		wrap_close(info->previous_pipe_read);
	}
	if (wrap_dup2(info->pipe_write, STDOUT_FILENO) < 0)
		return (true);
	wrap_close(info->pipe_read);
	wrap_close(info->pipe_write);
	return (false);
}
