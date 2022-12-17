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

#include "ms_parse.h"

#include "wrap.h"

static void	free_node(t_ms_and_or_list_node *node)
{
	ms_parse_free_pipe_list(&node->pipe_list);
	wrap_free(node);
}

void	ms_parse_free_and_or_list(t_ms_and_or_list *and_or_list)
{
	t_ms_and_or_list_node	*node_to_remove;

	while (and_or_list->head)
	{
		node_to_remove = and_or_list->head;
		and_or_list->head = node_to_remove->next;
		free_node(node_to_remove);
	}
	and_or_list->tail = NULL;
}
