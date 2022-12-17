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

static t_err	add_word(
	t_ms_parse_token_list_node **mut_head,
	t_ms_command *out,
	bool *out_syntax_error
)
{
	t_ms_word_list_node *const	node = wrap_malloc(sizeof(t_ms_word_list_node));

	if (!node || ms_parse_parse_word(mut_head, &node->word))
	{
		wrap_free(node);
		return (true);
	}
	if (!node->word)
	{
		wrap_free(node);
		*out_syntax_error = true;
		return (false);
	}
	node->next = NULL;
	if (out->value.simple->word_list.head)
		out->value.simple->word_list.tail->next = node;
	else
		out->value.simple->word_list.head = node;
	out->value.simple->word_list.tail = node;
	*out_syntax_error = false;
	return (false);
}

static t_err	add(
	t_ms_parse_token_list_node **mut_head,
	t_ms_command *out,
	bool *out_syntax_error
)
{
	t_ms_redirections *const	redirections = &out->value.simple->redirections;

	if (ms_parse_parse_command_is_redirection(mut_head))
	{
		if (ms_parse_parse_command_add_redirection(mut_head, redirections))
			return (true);
		if (!redirections->in.head && !redirections->out.head)
			*out_syntax_error = true;
		return (false);
	}
	return (add_word(mut_head, out, out_syntax_error));
}

t_err	ms_parse_parse_command_simple(
	t_ms_parse_token_list_node **mut_head,
	t_ms_redirections redirections,
	t_ms_command *out
)
{
	t_ms_command_simple *const	result
		= wrap_malloc(sizeof(t_ms_command_simple));
	bool						syntax_error;

	if (!result)
	{
		ms_parse_free_redirections(&redirections);
		return (true);
	}
	*result = (t_ms_command_simple){{NULL, NULL}, redirections};
	*out = (t_ms_command){MS_COMMAND_TYPE_SIMPLE, {.simple = result}};
	while (ms_parse_parse_command_is_redirection(mut_head)
		|| ms_parse_parse_command_is_word(*mut_head))
	{
		syntax_error = false;
		if (add(mut_head, out, &syntax_error) || syntax_error)
		{
			ms_parse_free_command(out);
			*out = (t_ms_command){MS_COMMAND_TYPE_INVALID, {NULL}};
			return (!syntax_error);
		}
	}
	return (false);
}
