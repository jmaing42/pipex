/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_putenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:05:37 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/30 21:24:19 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ms_expand.h"

#include <stdlib.h>

t_err	ms_expand_env_put(const char *key, const char *value)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*new_node;

	list = ms_expand_env_list_get();
	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_env_list_node));
	new_node->key = key;
	new_node->value = value;
	if (new_node == NULL)
		return (true);
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
