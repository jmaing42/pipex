/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_part_string_list.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:08:49 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 20:25:59 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>
#include "ms.h"
#include <stdio.h> //test only!!

static t_err	ms_execute_expansion(char *env_name, char **out)
{
	*out = getenv(env_name);
	if (*out == NULL)
		return (true);
	return (false);
}

t_err	ms_execute_word_part_string_list(
	t_ms_word_part_string_list *wps_list,
	t_stringbuilder *str
)
{
	t_ms_word_part_string_list_node	*node;
	char							*value;

	node = wps_list->head;
	while (node)
	{
		if (node->type == MS_WORD_PART_STRING_EXPANSION)
		{
			if (ms_execute_expansion(node->value, &value))
				return (true);
		}
		else
			value = node->value;
		printf("%s\n", value); //test_only
		stringbuilder_append_string(str, value);
		node = node->next;
	}
	return (false);
}
