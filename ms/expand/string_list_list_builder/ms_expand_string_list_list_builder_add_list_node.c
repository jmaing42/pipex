/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_add_list_node.c :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/01 13:25:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_types.h"
#include "ms_expand.h"

t_err	ms_expand_string_list_list_builder_add_list_node(
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