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
		if (node->type == ms_word_part_string_expansion
			&& printf("%*sExpansion - $%s\n", depth + 1, "", node->value) < 0)
			return (true);
		if (node->type == ms_word_part_string_no_expansion
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
	if (type == ms_word_part_unquoted)
	{
		if (printf("%*sUnquoted {\n", depth, "") < 0
			|| print_word_string_list(depth + 1, value.unquoted)
			|| printf("%*s}\n", depth, "") < 0)
			return (true);
	}
	else if (type == ms_word_part_single_quoted)
	{
		if (printf("%*sSingleQuoted - %s\n", depth, "", value.single_quoted)
			< 0)
			return (true);
		return (false);
	}
	else if (type == ms_word_part_double_quoted)
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
