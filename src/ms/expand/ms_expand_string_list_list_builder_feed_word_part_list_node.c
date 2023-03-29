/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_wor        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/29 17:05:10 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include "ms.h"

static const char	*get_string(t_ms_word_part_string_list_node *node)
{
	const char	*result;

	if (node->type == MS_WORD_PART_STRING_NO_EXPANSION)
		return (node->value);
	result = ms_expand_getenv(node->value);
	if (result)
		return (result);
	return ("");
}

static t_err	feed_node(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word_part_string_list_node *node,
	t_ms_word_part_type type
)
{
	return (
		ms_expand_string_list_list_builder_feed_string(
			self,
			get_string(node),
			type
		)
	);
}

static t_err	other(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word_part_string_list *string_list,
	t_ms_word_part_type type
)
{
	t_ms_word_part_string_list_node	*node;

	node = string_list->head;
	while (node)
	{
		if (feed_node(self, node, type))
			return (true);
		node = node->next;
	}
	return (false);
}

static t_err	single_quoted(
	t_ms_expand_string_list_list_builder *self,
	char *str
)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ms_expand_string_list_list_builder_feed_char(
				self, str[i], MS_WORD_PART_SINGLE_QUOTED))
			return (true);
		i++;
	}
	return (false);
}

t_err	ms_expand_string_list_list_builder_feed_word_part_list_node(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word_part_list_node *node
)
{
	if (node->type == MS_WORD_PART_SINGLE_QUOTED)
		return (single_quoted(self, node->value.single_quoted));
	return (other(self, node->value.any, node->type));
}
