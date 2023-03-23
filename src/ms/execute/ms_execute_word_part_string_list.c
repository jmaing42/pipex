/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_part_string_list.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:08:49 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/23 22:38:58 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include "ms.h"
#include <stdio.h> //test only!!

static t_err	ms_execute_expansion(char *value)
{
	
}

t_err	ms_execute_word_part_string_list(t_ms_word_part_string_list *wps_list)
{
	t_ms_word_part_string_list_node	*node;

	node = wps_list->head;
	while (node)
	{
		if (node->type == MS_WORD_PART_STRING_EXPANSION)
			return (ms_execute_expansion(node->value));
		printf("%s\n", node->value);
		node = node->next;
	}
	return (false);
}
