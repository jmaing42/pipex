/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_list        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:18:18 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 16:18:12 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"
#include "ft_memory.h"

#include <stdlib.h>

t_err	ms_expand_string_list_list_node_add(
	t_ms_expand_string_list_list *list
)
{
	t_ms_expand_string_list_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_string_list_list_node));
	if (new_node == NULL)
		return (NULL);
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
		return (false);
	}
	list->tail->next = new_node;
	list->tail = list->tail->next;
	return (false);
}
