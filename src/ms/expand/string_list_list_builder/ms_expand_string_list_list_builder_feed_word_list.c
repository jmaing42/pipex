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
// TODO: test
		if (self->builder != NULL
			&& ms_expand_string_list_list_builder_fill_node(
				&self->builder, &self->list.tail->list))
			return (true);
		node = node->next;
		self->need_new_list_list = true;
	}
	return (false);
}
