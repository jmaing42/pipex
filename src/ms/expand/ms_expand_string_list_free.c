/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_free.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:32:27 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 20:40:55 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include <stdlib.h>

void	ms_expand_string_list_free(t_ms_expand_string_list *list)
{
	t_ms_expand_string_list_node	*node;

	node = list->head;
	while (node)
	{
		free(node->str);
		node = node->next;
	}
}
