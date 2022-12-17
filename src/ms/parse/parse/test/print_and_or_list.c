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

#include "test.h"

#include <stdio.h>

t_err	print_and_or_list(int depth, t_ms_and_or_list *and_or_list)
{
	t_ms_and_or_list_node	*node;
	bool					first;

	if (printf("%*sAndOrList {\n", depth, "") < 0)
		return (true);
	first = true;
	node = and_or_list->head;
	while (node)
	{
		if (!first)
		{
			if (node->is_and && printf("%*sAND\n", depth, ""))
				return (true);
			if (!node->is_and && printf("%*sOR\n", depth, ""))
				return (true);
		}
		if (print_pipe_list(depth + 1, &node->pipe_list))
			return (true);
		node = node->next;
		first = false;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}
