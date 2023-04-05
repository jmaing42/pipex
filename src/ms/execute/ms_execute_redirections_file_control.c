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

t_err	ms_execute_redirections_control_files(t_ms_execute_pipe_info *info)
{
	if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO))
		return (true);
	if (wrap_dup2(info->pipe_write, STDOUT_FILENO))
		return (true);
	wrap_close(info->previous_pipe_read);
	wrap_close(info->pipe_read);
	wrap_close(info->pipe_write);
	return (false);
}
