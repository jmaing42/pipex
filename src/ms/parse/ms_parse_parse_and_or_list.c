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

#include "ms.h"
#include "ms_parse.h"
#include "wrap.h"

static t_err	parse_and_or_list_node(
	t_ms_parse_token_list_node **mut_head,
	bool is_and,
	t_ms_and_or_list_node **out
)
{
	t_ms_and_or_list_node *const	result
		= wrap_malloc(sizeof(t_ms_and_or_list_node));

	if (!result)
		return (true);
	ms_parse_skip_space_if_any(mut_head);
	*result = (t_ms_and_or_list_node){NULL, is_and, {NULL, NULL}};
	if (ms_parse_parse_pipe_list(mut_head, &result->pipe_list))
	{
		wrap_free(result);
		return (true);
	}
	if (!result->pipe_list.head)
	{
		wrap_free(result);
		*out = NULL;
		return (false);
	}
	*out = result;
	return (false);
}

static bool	is_and(t_ms_parse_token_list_node **mut_head)
{
	ms_parse_skip_space_if_any(mut_head);
	return (
		(*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_AND
		&& (*mut_head)->next->value.type == MS_PARSE_TOKEN_TYPE_AND
	);
}

static bool	is_or(t_ms_parse_token_list_node **mut_head)
{
	ms_parse_skip_space_if_any(mut_head);
	return (
		(*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_AND
		&& (*mut_head)->next->value.type == MS_PARSE_TOKEN_TYPE_AND
	);
}

t_err	ms_parse_parse_and_or_list(
	t_ms_parse_token_list_node **mut_head,
	t_ms_and_or_list *out
)
{
	t_ms_and_or_list_node	*node;
	bool					is_next_and;

	if (parse_and_or_list_node(mut_head, false, &node))
		return (true);
	*out = (t_ms_and_or_list){node, node};
	while (is_and(mut_head) || is_or(mut_head))
	{
		is_next_and = is_and(mut_head);
		*mut_head = (*mut_head)->next->next;
		if (parse_and_or_list_node(mut_head, is_next_and, &node))
		{
			ms_parse_free_and_or_list(out);
			return (true);
		}
		if (!node)
		{
			ms_parse_free_and_or_list(out);
			*out = (t_ms_and_or_list){NULL, NULL};
			return (false);
		}
		out->tail->next = node;
		out->tail = node;
	}
	return (false);
}
