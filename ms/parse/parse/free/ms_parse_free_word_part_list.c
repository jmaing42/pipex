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

static void	free_node(t_ms_word_part_list_node *node)
{
	ms_parse_free_word_part(node->type, node->value);
	wrap_free(node);
}

void	ms_parse_free_word_part_list(t_ms_word_part_list *list)
{
	t_ms_word_part_list_node	*node_to_remove;

	while (list->head)
	{
		node_to_remove = list->head;
		list->head = node_to_remove->next;
		free_node(node_to_remove);
	}
	list->tail = NULL;
}
