/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_list        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:05:40 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 15:27:59 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_types.h"
#include "ms_execute.h"
#include "ms_expand.h"

t_err	ms_expand_string_list_node_add(
	t_ms_expand_string_list *list
)
{
	t_ms_expand_string_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_node));
	if (new_node == NULL)
		return (true);
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
