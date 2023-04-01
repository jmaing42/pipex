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

#include "ft_memory.h"
#include "ms_expand.h"

#include <stdlib.h>

// TODO: 이미 있었으면 삭제

t_err	ms_expand_env_put(const char *key, const char *value)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*new_node;

	list = ms_expand_env_list_get();
	new_node = ft_memory_allocate(1, sizeof(t_ms_expand_env_list_node));
	if (new_node == NULL)
		return (true);
	new_node->key = key;
	new_node->value = value;
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
