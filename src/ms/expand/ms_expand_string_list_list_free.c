/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_free.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:35:03 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 21:35:50 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include <stdlib.h>

void	ms_expand_string_list_list_free(t_ms_expand_string_list_list *list)
{
	t_ms_expand_string_list_list_node	*node;

	node = list->head;
	while (node)
	{
		ms_expand_string_list_free(&node->list);
		node = node->next;
	}
}
