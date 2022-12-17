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

static t_err	fill_remain_redirections(
	t_ms_parse_token_list_node **mut_head,
	t_ms_command *out
)
{
	t_ms_redirections *const	redirections
		= &out->value.compound->redirections;

	while (ms_parse_parse_command_is_redirection(mut_head))
	{
		if (ms_parse_parse_command_add_redirection(mut_head, redirections))
		{
			ms_parse_free_command(out);
			return (true);
		}
		if (!redirections->in.head && !redirections->out.head)
		{
			ms_parse_free_command(out);
			*out = (t_ms_command){MS_COMMAND_TYPE_INVALID, {NULL}};
			return (false);
		}
	}
	return (true);
}

t_err	ms_parse_parse_command_compound(
	t_ms_parse_token_list_node **mut_head,
	t_ms_redirections redirections,
	t_ms_command *out
)
{
	t_ms_command_compound *const	result
		= wrap_malloc(sizeof(t_ms_command_compound));

	*mut_head = (*mut_head)->next;
	if (!result || ms_parse_parse_and_or_list(mut_head, &result->and_or_list))
	{
		ms_parse_free_redirections(&redirections);
		wrap_free(result);
		return (true);
	}
	ms_parse_parse_util_skip_space_if_any(mut_head);
	if (!result->and_or_list.head
		|| (*mut_head)->value.type != MS_PARSE_TOKEN_TYPE_RIGHT_PARENTHESIS)
	{
		ms_parse_free_redirections(&redirections);
		wrap_free(result);
		*out = (t_ms_command){MS_COMMAND_TYPE_INVALID, {NULL}};
		return (false);
	}
	*mut_head = (*mut_head)->next;
	result->redirections = redirections;
	out->type = MS_COMMAND_TYPE_COMPOUND;
	out->value.compound = result;
	return (fill_remain_redirections(mut_head, out));
}
