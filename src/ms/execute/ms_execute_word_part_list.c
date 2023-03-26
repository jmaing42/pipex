/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_part_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:02:10 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 20:47:17 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include "ms.h"
#include <stdio.h> //test only

static t_err	ms_execute_single_quoted(
	char *single_quoted,
	t_stringbuilder *str
)
{
	printf("%s\n", single_quoted);
	if (stringbuilder_append_string(str, single_quoted))
	{
		stringbuilder_free(str);
		return (true);
	}
	return (false);
}

t_err	ms_execute_word_part_list(t_ms_word_part_list *wp_list, char **out_arg)
{
	t_ms_word_part_list_node	*node;
	t_stringbuilder				*str;

	str = new_stringbuilder(ALLOC_SIZE);
	if (str == NULL)
		return (true);
	node = wp_list->head;
	while (node)
	{
		if (node->type == MS_WORD_PART_UNQUOTED
			&& ms_execute_word_part_string_list(node->value.unquoted, str))
			return (true);
		else if (node->type == MS_WORD_PART_SINGLE_QUOTED
			&& ms_execute_single_quoted(node->value.single_quoted, str))
			return (true);
		else if (node->type == MS_WORD_PART_DOUBLE_QUOTED
			&& ms_execute_word_part_string_list(node->value.double_quoted, str))
			return (true);
		node = node->next;
	}
	*out_arg = stringbuilder_to_string(str, 0);
	stringbuilder_free(str);
	if (*out_arg == NULL)
		return (true);
	return (false);
}
