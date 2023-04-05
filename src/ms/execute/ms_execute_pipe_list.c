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

#include <stdbool.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ft_memory.h"
#include "ms.h"

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_ms_execute_pipe_info	info;

	ft_memory_set(&info, 0, sizeof(t_ms_execute_pipe_info));
	info.node = pipe_list->head;
	info.is_first = true;
	while (info.node)
	{
		if (l.node->next)
		{
			if (ft_os_pipe(&l.pipe_write, &l.pipe_read))
				return (true);
		}
		ms_execute_command(&l.node->command, &l.piped_input, &l.piped_output);
		l.node = l.node->next;
		l.is_first = false;
	}
	return (false);
}
