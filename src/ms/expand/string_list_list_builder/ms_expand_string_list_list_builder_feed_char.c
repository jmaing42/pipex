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

#include "ms_expand.h"

#include "ft_memory.h"
#include "ft_stringbuilder.h"
#include "ft_types.h"
#include "ft_types_char.h"
#include "ms.h"
#include <stdbool.h>

static t_err	push_asterisk_node(t_ms_expand_string_list_list_builder *self)
{
	return (ms_expand_string_list_list_builder_fill_node(
			&self->builder, &self->list.tail->list));
}

static t_err	push_space_node(t_ms_expand_string_list_list_builder *self)
{
	self->need_new_list_list = true;
	return (ms_expand_string_list_list_builder_fill_node(
			&self->builder, &self->list.tail->list));
}

t_err	ms_expand_string_list_list_builder_feed_char(
	t_ms_expand_string_list_list_builder *self,
	const char ch,
	t_ms_word_part_type type
)
{
	if (self->builder == NULL)
	{
		self->builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
		if (self->builder == NULL)
			return (true);
	}
	if (type == MS_WORD_PART_UNQUOTED && ft_types_char_space(ch))
		return (push_space_node(self));
	else if (type == MS_WORD_PART_UNQUOTED && ch == '*')
		return (push_asterisk_node(self));
	if (stringbuilder_append_char(self->builder, ch))
		return (true);
	return (false);
}
