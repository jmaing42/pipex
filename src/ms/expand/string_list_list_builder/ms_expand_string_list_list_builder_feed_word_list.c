/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_wor        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/30 15:03:55 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include "ms.h"

t_err	ms_expand_string_list_list_builder_feed_word_list(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word_list *list
)
{
	t_ms_word_list_node	*node;

	node = list->head;
	while (node)
	{
		if (ms_expand_string_list_list_builder_feed_word(self, node->word))
			return (true);
		if (self->builder != NULL
			&& ms_expand_string_list_list_builder_fill_node(
				&self->builder, &self->list.tail->list))
			return (true);
		node = node->next;
	}
	return (false);
}
