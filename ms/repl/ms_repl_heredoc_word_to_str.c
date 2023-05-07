/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_repl_heredoc_word_to_str.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:30:30 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/07 16:58:36 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_repl.h"

#include "ms_expand.h"
#include "ft_stringbuilder.h"


static t_err	double_and_unquoted(
	t_ms_word_part_string_list *list,
	t_stringbuilder *builder
)
{
	t_ms_word_part_string_list_node	*node;

	node = list->head;
	while (node)
	{
		if (ft_stringbuilder_append_string(builder, node->value))
			return (true);
		node = node->next;
	}
	return (false);
}

static t_err	word_to_str(
	t_ms_word_part_list_node *node,
	t_stringbuilder *builder
)
{
	if (node->type == ms_word_part_double_quoted)
	{
		if (double_and_unquoted(node->value.double_quoted, builder))
			return (true);
	}
	else if (node->type == ms_word_part_unquoted)
	{
		if (double_and_unquoted(node->value.unquoted, builder))
			return (true);
	}
	else if (node->type == ms_word_part_single_quoted)
	{
		if (ft_stringbuilder_append_string(
				builder, node->value.single_quoted))
			return (true);
	}
	return (false);
}

t_err	ms_repl_heredoc_word_to_str(
	t_ms_word_part_list *list,
	char **out_path
)
{
	t_ms_word_part_list_node	*node;
	t_stringbuilder				*builder;

	builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
	if (builder == NULL)
		return (true);
	node = list->head;
	while (node)
	{
		if (word_to_str(node, builder))
		{
			ft_stringbuilder_free(builder);
			return (true);
		}
		node = node->next;
	}
	*out_path = ft_stringbuilder_to_string(builder, 0);
	ft_stringbuilder_free(builder);
	return (false);
}
