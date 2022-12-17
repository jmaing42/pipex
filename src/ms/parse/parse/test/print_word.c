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

#include "test.h"

#include <stdio.h>

static t_err	print_word_string_list(
	int depth,
	t_ms_word_part_string_list *list
)
{
	t_ms_word_part_string_list_node	*node;

	if (printf("%*sStringList {\n", depth, "") < 0)
		return (true);
	node = list->head;
	while (node)
	{
		if (node->type == MS_WORD_PART_STRING_EXPANSION
			&& printf("%*sExpansion - $%s\n", depth + 1, "", node->value) < 0)
			return (true);
		if (node->type == MS_WORD_PART_STRING_NO_EXPANSION
			&& printf("%*sNoExpansion - %s\n", depth + 1, "", node->value) < 0)
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}

static t_err	print_word_part(
	int depth,
	t_ms_word_part_type type,
	t_ms_word_part_value value
)
{
	if (type == MS_WORD_PART_UNQUOTED)
	{
		if (printf("%*sUnquoted {\n", depth, "") < 0
			|| print_word_string_list(depth + 1, value.unquoted)
			|| printf("%*s}\n", depth, "") < 0)
			return (true);
	}
	else if (type == MS_WORD_PART_SINGLE_QUOTED)
	{
		if (printf("%*sSingleQuoted - %s\n", depth, "", value.single_quoted)
			< 0)
			return (true);
		return (false);
	}
	else if (type == MS_WORD_PART_DOUBLE_QUOTED)
	{
		if (printf("%*sDoubleQuoted {\n", depth, "") < 0
			|| print_word_string_list(depth + 1, value.double_quoted)
			|| printf("%*s}\n", depth, "") < 0)
			return (true);
	}
	else
		return (true);
	return (false);
}

t_err	print_word(int depth, t_ms_word *word)
{
	t_ms_word_part_list_node	*node;

	if (printf("%*sWord {\n", depth, "") < 0)
		return (true);
	node = word->part_list.head;
	while (node)
	{
		if (print_word_part(depth + 1, node->type, node->value))
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}
