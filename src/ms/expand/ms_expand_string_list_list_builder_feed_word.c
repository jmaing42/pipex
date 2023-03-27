/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_wor        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/27 22:38:54 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ms_expand.h"

#include "ms.h"

t_err	ms_expand_string_list_list_builder_feed_word(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word *word
)
{
	t_ms_expand_string_list_list_node	*node;

	node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_list_node));
	if (node == NULL)
		return (true);
	if (self->list.head == NULL)
	{
		self->list.head = node;
		self->list.tail = node;
	}
	else
	{
		self->list.tail->next = node;
		self->list.tail = self->list.tail->next;
	}
	if (ms_expand_string_list_list_builder_feed_word_part_list(
		self, &word->part_list))
		return (true);
	return (false);
}
