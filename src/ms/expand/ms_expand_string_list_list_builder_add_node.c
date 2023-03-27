/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_node        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:05:40 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 21:59:01 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stringbuilder.h"
#include "ft_types.h"
#include "ms_execute.h"

static t_err	fill_node(
	t_stringbuilder *builder,
	t_ms_expand_string_list_list_node *node
)
{
	char	*str;
	return (false);
}

t_err	ms_expand_string_list_list_builder_add_node(
	t_ms_expand_string_list_list_builder *self
)
{
	t_ms_expand_string_list_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_list_node));
	if (new_node == NULL)
		return (true);
	fill_node(self->builder, new_node);
	if (self->list.head == NULL)
	{
		self->list.head = new_node;
		self->list.tail = new_node;
	}
	else
	{
		self->list.tail->next = new_node;
		self->list.tail = new_node;
	}
	return (false);
}
