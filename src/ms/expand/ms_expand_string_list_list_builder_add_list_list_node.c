/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_list        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:18:18 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 14:25:29 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"
#include "ft_memory.h"

#include <stdlib.h>

t_err	ms_expand_string_list_list_builder_add_list_list_node(
	t_ms_expand_string_list_list_builder *self
)
{
	t_ms_expand_string_list_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_list_node));
	if (new_node == NULL)
		return (NULL);
	if (self->list.head == NULL)
	{
		self->list.head = new_node;
		self->list.tail = new_node;
		return (false);
	}
	if (ms_expand_string_list_list_builder_add_list_node(self))
	{
		free(new_node);
		return (true);
	}
	self->list.tail = new_node;
	self->list.tail = self->list.tail->next;
	return (false);
}
