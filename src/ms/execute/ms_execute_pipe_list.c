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
#include "ms.h"

typedef struct s_locals
{
	t_ms_pipe_list_node	*node;
	bool				is_first;
	int					previous_pipe_read;
	int					pipe_write;
	int					pipe_read;
	int					*piped_input;
	int					*piped_output;
}	t_locals;

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_locals	l;

	l.node = pipe_list->head;
	l.is_first = true;
	while (l.node)
	{
		if (l.node->next)
		{
			if (ft_os_pipe(&l.pipe_write, &l.pipe_read))
				return (true);
		}
		l.piped_input = NULL;
		l.piped_output = NULL;
		// TODO:
		ms_execute_command(&l.node->command, l.piped_input, l.piped_output);
		l.node = l.node->next;
		l.is_first = false;
	}
	return (false);
}
