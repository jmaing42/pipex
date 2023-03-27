/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_node        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:05:40 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 22:12:03 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stringbuilder.h"
#include "ft_types.h"
#include "ms_execute.h"
#include "ms_expand.h"

static t_err	fill_node(
	t_stringbuilder *builder,
	t_ms_expand_string_list_node *node
)
{
	char	*str;

	str = stringbuilder_to_string(builder, 0);
	if (str == NULL)
		return (true);
	node->str = str;
	return (false);
}

t_err	ms_expand_string_list_list_builder_add_node(
	t_ms_expand_string_list_list_builder *self
)
{
	t_ms_expand_string_list			*list;
	t_ms_expand_string_list_node	*new_node;

	list = &self->list.tail->list;
	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_node));
	if (new_node == NULL)
		return (true);
	fill_node(self->builder, new_node);
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = list->tail->next;
	}
	return (false);
}
