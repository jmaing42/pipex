/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_free.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:32:27 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 23:15:26 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include <stdlib.h>

void	ms_expand_string_list_free(t_ms_expand_string_list *list)
{
	t_ms_expand_string_list_node	*node;
	t_ms_expand_string_list_node	*tmp;

	node = list->head;
	while (node)
	{
		tmp = node->next;
		free(node->str);
		free(node);
		node = tmp;
	}
}
