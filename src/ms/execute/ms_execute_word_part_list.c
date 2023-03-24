/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_part_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:02:10 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 19:37:34 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include "ms.h"
#include <stdio.h> //test only
t_err	ms_execute_word_part_list(t_ms_word_part_list *wp_list)
{
	t_ms_word_part_list_node	*node;

	node = wp_list->head;
	while (node)
	{
		if (node->type == MS_WORD_PART_UNQUOTED)
			return (ms_execute_word_part_string_list(node->value.unquoted));
		else if (node->type == MS_WORD_PART_SINGLE_QUOTED)
			printf("%s\n", node->value.single_quoted);
		else
			return (
				ms_execute_word_part_string_list(node->value.double_quoted));
		node = node->next;
	}
	return (false);
}
