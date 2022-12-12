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

t_err	ms_parse_parse_command_add_redirection(
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
