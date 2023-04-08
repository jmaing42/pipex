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

#include "wrap.h"

static t_err	parse_pipe_list_node(
	t_ms_parse_token_list_node **mut_head,
	t_ms_pipe_list_node **out
)
{
	t_ms_pipe_list_node *const	result
		= wrap_malloc(sizeof(t_ms_pipe_list_node));

	if (!result)
		return (true);
	ms_parse_parse_util_skip_space_if_any(mut_head);
	result->next = NULL;
	if (ms_parse_parse_command(mut_head, &result->command))
	{
		wrap_free(result);
		return (true);
	}
	if (!result->command.value.any)
	{
		wrap_free(result);
		*out = NULL;
		return (false);
	}
	*out = result;
	return (false);
}

t_err	ms_parse_parse_pipe_list(
	t_ms_parse_token_list_node **mut_head,
	t_ms_pipe_list *out
)
{
	t_ms_pipe_list_node	*node;

	if (parse_pipe_list_node(mut_head, &node))
		return (true);
	*out = (t_ms_pipe_list){node, node};
	while ((*mut_head)->value.type == ms_parse_token_type_or)
	{
		*mut_head = (*mut_head)->next;
		if (parse_pipe_list_node(mut_head, &node))
		{
			ms_parse_free_pipe_list(out);
			return (true);
		}
		if (!node)
		{
			ms_parse_free_pipe_list(out);
			*out = (t_ms_pipe_list){NULL, NULL};
			return (false);
		}
		out->tail->next = node;
		out->tail = node;
	}
	return (false);
}
