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

static bool	is_word(t_ms_parse_token_list_node *head)
{
	return (head->value.type == MS_PARSE_TOKEN_TYPE_WORD
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD)
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
	);
}

static bool	is_redirection(t_ms_parse_token_list_node **mut_head)
{
	ms_parse_skip_space_if_any(mut_head);
	return (((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& is_word((*mut_head)->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& (*mut_head)->next->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& is_word((*mut_head)->next->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& is_word((*mut_head)->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& (*mut_head)->next->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& is_word((*mut_head)->next->next))
	);
}

static t_err	add_node(
	t_ms_redirections *mut_redirections,
	bool is_output,
	bool is_special,
	t_ms_word *word
)
{
	t_ms_redirection_list_node *const	node
		= wrap_malloc(sizeof(t_ms_parse_token_list_node));

	if (!node)
		ms_parse_free_redirections(mut_redirections);
	if (!node)
		return (true);
	*node = (t_ms_redirection_list_node){NULL, is_special, word};
	if (is_output)
	{
		if (mut_redirections->stdout.head)
			mut_redirections->stdout.tail->next = node;
		else
			mut_redirections->stdout.head = node;
		mut_redirections->stdout.tail = node;
	}
	else
	{
		if (mut_redirections->stdin.head)
			mut_redirections->stdin.tail->next = node;
		else
			mut_redirections->stdin.head = node;
		mut_redirections->stdin.tail = node;
	}
	return (false);
}

static t_err	add_redirection(
	t_ms_parse_token_list_node **mut_head,
	t_ms_redirections *mut_redirections
)
{
	bool		is_output;
	bool		is_special;
	t_ms_word	*word;

	is_output = (*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON;
	is_special = ((*mut_head)->value.type == (*mut_head)->next->value.type);
	*mut_head = (*mut_head)->next;
	if (is_special)
		*mut_head = (*mut_head)->next;
	ms_parse_skip_space_if_any(mut_head);
	if (ms_parse_parse_word(mut_head, &word))
	{
		ms_parse_free_redirections(mut_redirections);
		return (true);
	}
	if (!word)
	{
		ms_parse_free_redirections(mut_redirections);
		*mut_redirections = (t_ms_redirections){{NULL, NULL}, {NULL, NULL}};
		return (false);
	}
	return (add_node(mut_redirections, is_output, is_special, word));
}

t_err	ms_parse_parse_command(
	t_ms_parse_token_list_node **mut_head,
	t_ms_command *out
)
{
	t_ms_redirections	redirections;

	redirections = (t_ms_redirections){{NULL, NULL}, {NULL, NULL}};
	while (is_redirection(mut_head))
	{
		if (add_redirection(mut_head, &redirections))
			return (true);
		if (!redirections.stdin.head && !redirections.stdout.head)
		{
			*out = (t_ms_command){MS_COMMAND_TYPE_INVALID, {NULL}};
			return (false);
		}
	}
	if ((*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS)
		return (ms_parse_parse_command_compound(mut_head, redirections, out));
	if (is_word(*mut_head))
		return (ms_parse_parse_command_simple(mut_head, redirections, out));
	ms_parse_free_redirections(&redirections);
	*out = (t_ms_command){MS_COMMAND_TYPE_INVALID, {NULL}};
	return (false);
}
