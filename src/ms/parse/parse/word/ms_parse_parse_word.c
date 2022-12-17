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

static t_err	add_part(
	t_ms_word *mut_word,
	t_ms_word_part_type type,
	t_ms_word_part_value always_consume_value
)
{
	t_ms_word_part_list_node *const	node
		= wrap_malloc(sizeof(t_ms_word_part_list_node));

	if (!node)
	{
		ms_parse_free_word_part(type, always_consume_value);
		return (true);
	}
	node->next = NULL;
	node->type = type;
	node->value = always_consume_value;
	if (mut_word->part_list.head)
		mut_word->part_list.tail->next = node;
	else
		mut_word->part_list.head = node;
	mut_word->part_list.tail = node;
	return (false);
}

static bool	is_word(t_ms_parse_token_list_node *head)
{
	return (
		head->value.type == MS_PARSE_TOKEN_TYPE_WORD
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED
	);
}

static t_ms_word_part_type	type(t_ms_parse_token_list_node *head)
{
	if (head->value.type == MS_PARSE_TOKEN_TYPE_WORD)
		return (MS_WORD_PART_UNQUOTED);
	if (head->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
		return (MS_WORD_PART_SINGLE_QUOTED);
	return (MS_WORD_PART_DOUBLE_QUOTED);
}

static t_err	fill_list(
	t_ms_parse_token_list_node **mut_head,
	t_ms_word *mut_word
)
{
	t_ms_word_part_value	value;
	t_err					error;

	while (is_word(*mut_head))
	{
		if ((*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_WORD)
			error = ms_parse_parse_word_part_unquoted(
					(*mut_head)->value.data, &value.unquoted);
		if ((*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
			error = ms_parse_parse_word_part_single_quoted(
					(*mut_head)->value.data, &value.single_quoted);
		if ((*mut_head)->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
			error = ms_parse_parse_word_part_double_quoted(
					(*mut_head)->value.data, &value.double_quoted);
		if (error || !value.any || add_part(mut_word, type(*mut_head), value))
		{
			ms_parse_free_word_part_list(&mut_word->part_list);
			return (error);
		}
		*mut_head = (*mut_head)->next;
	}
	return (false);
}

t_err	ms_parse_parse_word(
	t_ms_parse_token_list_node **mut_head,
	t_ms_word **out
)
{
	t_ms_word *const	result = wrap_malloc(sizeof(t_ms_word));
	t_err				error;

	if (!result)
		return (true);
	if (is_word(*mut_head))
	{
		wrap_free(result);
		*out = NULL;
		return (false);
	}
	result->part_list = (t_ms_word_part_list){NULL, NULL};
	if (fill_list(mut_head, result))
	{
		wrap_free(result);
		return (true);
	}
	error = fill_list(mut_head, result);
	if (error || !result->part_list.head)
	{
		wrap_free(result);
		*out = NULL;
		return (error);
	}
	return (false);
}
