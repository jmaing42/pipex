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

#include "ms_parse.h"

#include <stdlib.h>

t_err	ms_parse_tokenize_add_simple_token(
	t_ms_parse_token_list *list,
	t_ms_parse_token_type type
)
{
	t_ms_parse_token_list_node *const	node
		= malloc(sizeof(t_ms_parse_token_list_node));

	if (!node)
	{
		free(node);
		return (true);
	}
	node->next = NULL;
	node->value.type = type;
	node->value.data = NULL;
	if (list->head)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	return (false);
}
