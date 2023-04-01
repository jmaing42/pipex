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

t_err	test_and_or_list(t_ms_and_or_list *and_or_list)
{
	t_ms_and_or_list_node	*node;

	node = and_or_list->head;
	while (node)
	{
		if (test_pipe_list(&node->pipe_list))
			return (true);
		node = node->next;
	}
	return (false);
}
