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

#include "ms_builtin.h"

#include <stdlib.h>

#include "ft_cstring.h"
#include "ms_execute.h"
#include "ms_expand.h"
#include "wrap.h"

static void	delete_next_node(t_ms_expand_env_list_node *front)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*delete_node;

	list = ms_expand_env_list_get();
	if (front == NULL)
	{
		delete_node = list->head;
		wrap_free(delete_node->key);
		wrap_free(delete_node->value);
		wrap_free(delete_node);
		list->head = NULL;
		list->tail = NULL;
		return ;
	}
	delete_node = front->next;
	front->next = delete_node->next;
	if (delete_node == list->tail)
		list->tail = front;
	wrap_free(delete_node->key);
	wrap_free(delete_node->value);
	wrap_free(delete_node);
}

void	ms_builtin_unset(char *key)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*node;
	t_ms_expand_env_list_node	*front;

	list = ms_expand_env_list_get();
	front = NULL;
	node = list->head;
	while (node)
	{
		if (ft_cstring_equals(key, node->key))
		{
			delete_next_node(front);
			return ;
		}
		front = node;
		node = node->next;
	}
	ms_execute_globals()->exit_status = EXIT_SUCCESS;
}
