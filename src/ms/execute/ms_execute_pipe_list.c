/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipe_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/24 22:42:22 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ft_memory.h"
#include "ms.h"

typedef struct s_locals
{
	t_ms_pipe_list_node	*node;
	bool				is_first;
	int					previous_pipe_read;
	int					pipe_write;
	int					pipe_read;
	int					piped_input;
	int					piped_output;
}	t_locals;

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_locals	l;

	ft_memory_set(&l, 0, sizeof(t_locals));
	l.node = pipe_list->head;
	l.is_first = true;
	while (l.node)
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
