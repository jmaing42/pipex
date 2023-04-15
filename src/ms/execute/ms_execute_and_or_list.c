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

#include "ft_types.h"
#include "ms.h"

t_err	ms_execute_and_or_list(t_ms_and_or_list *and_or_list)
{
	t_ms_and_or_list_node	*node;

	node = and_or_list->head;
	while (node)
	{
		if (node == and_or_list->head)
		{
			if (ms_execute_pipe_list(&node->pipe_list))
				return (true);
		}
		else if (node->is_and && !ms_execute_globals()->exit_status)
		{
			if (ms_execute_pipe_list(&node->pipe_list))
				return (true);
		}
		else if (!node->is_and && ms_execute_globals()->exit_status)
		{
			if (ms_execute_pipe_list(&node->pipe_list))
				return (true);
		}
		node = node->next;
	}
	return (false);
}
