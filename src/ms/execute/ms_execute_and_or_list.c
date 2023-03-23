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
	bool					succeed;

	if (ms_execute_pipe_list(&and_or_list->head->pipe_list))
		return (true);
	succeed = ms_execute_globals()->exit_status == 0;
	node = and_or_list->head->next;
	while (node)
	{
		if (!!node->is_and == succeed)
		{
			if (ms_execute_pipe_list(&node->pipe_list))
				return (true);
		}
		if (node->is_and)
			succeed = (succeed && ms_execute_globals()->exit_status == 0);
		else
			succeed = (succeed || ms_execute_globals()->exit_status == 0);
		node = node->next;
	}
	return (false);
}
