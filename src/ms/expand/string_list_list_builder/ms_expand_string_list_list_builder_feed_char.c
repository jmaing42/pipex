/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_cha        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:55:37 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 21:54:03 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stringbuilder.h"
#include "ft_types.h"
#include "ms.h"
#include "ms_expand.h"

static bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (true);
	return (false);
}

static t_err	push_asterisk_node(t_ms_expand_string_list_list_builder *self)
{
	if (ms_expand_string_list_node_add(&self->list.tail->list)
		|| ms_expand_string_list_list_builder_fill_node(
			&self->builder, &self->list.tail->list))
		return (true);
	return (false);
}

static t_err	push_space_node(t_ms_expand_string_list_list_builder *self)
{
	if (ms_expand_string_list_node_add(&self->list.tail->list)
		|| ms_expand_string_list_list_builder_fill_node(
			&self->builder, &self->list.tail->list)
		|| ms_expand_string_list_list_node_add(&self->list))
		return (true);
	return (false);
}

t_err	ms_expand_string_list_list_builder_feed_char(
	t_ms_expand_string_list_list_builder *self,
	const char ch,
	t_ms_word_part_type type
)
{
	if (self->builder == NULL)
	{
		self->builder = new_stringbuilder(STRING_BUILDER_SIZE);
		if (self->builder == NULL)
			return (true);
	}
	if (type == MS_WORD_PART_UNQUOTED && is_space(ch))
		return (push_space_node(self));
	else if (type != MS_WORD_PART_SINGLE_QUOTED && ch == '*')
		return (push_asterisk_node(self));
	if (stringbuilder_append_char(self->builder, ch))
		return (true);
	return (false);
}
