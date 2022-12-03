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

static t_err	internal(
	t_ms_parse_token_list_node **head,
	t_ms **mut
)
{
	t_ms_part_simple	tmp;

	while (true)
	{
		ms_parse_skip_space_if_any(head);
		if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD)
			return (ms_parse_parse_ms_simple(head, mut));
		if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS)
			return (ms_parse_parse_ms_compound(head, mut));
		if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& (*head)->next->value.type == MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON)
		{
			*head = (*head)->next->next;
			ms_parse_skip_space_if_any(head);
			if (ms_parse_parse_ms_simple_part(head, &tmp))
			{
				ms_free(*mut);
				return (true);
			}
			if (!tmp.length)
			{
				ms_free(*mut);
				*mut = NULL;
				return (false);
			}
		}
	}
}

t_err	ms_parse_parse_ms(
	t_ms_parse_token_list_node **head,
	t_ms **out
)
{
	*out = malloc(sizeof(t_ms));
	if (!*out)
		return (true);
	(*out)->stdin = (t_ms_part_special_list){NULL, NULL};
	(*out)->stdout = (t_ms_part_special_list){NULL, NULL};
	return (internal(head, out));
}
