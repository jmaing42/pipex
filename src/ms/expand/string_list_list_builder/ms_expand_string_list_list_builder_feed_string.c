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

#include "ft_stringbuilder.h"
#include "ms.h"
#include "ft_types_char.h"

static t_err	wildcard_case(t_ms_expand_string_list_list_builder *self)
{
	if (self->builder == NULL)
		self->builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
	if (self->builder == NULL)
		return (true);
	if (ms_expand_string_list_list_builder_fill_node(
			&self->builder, &self->list.tail->list))
		return (true);
	return (false);
}

static t_err	add_new_node(t_ms_expand_string_list_list_builder *self)
{
	if (!self->need_new_list_list)
		return (false);
	if (ms_expand_string_list_list_builder_add_list_list_node(
			&self->list))
		return (true);
	self->need_new_list_list = false;
	return (false);
}

t_err	ms_expand_string_list_list_builder_feed_string(
	t_ms_expand_string_list_list_builder *self,
	const char *str,
	t_ms_word_part_type type
)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (self->need_new_list_list
			&& type == MS_WORD_PART_UNQUOTED
			&& ft_types_char_space(str[i]))
			continue ;
		if (add_new_node(self))
			return (true);
		if (ms_expand_string_list_list_builder_feed_char(
				self, str[i], type))
			return (true);
		if (type == MS_WORD_PART_UNQUOTED
			&& str[i] == '*' && str[i + 1] == '\0')
		{
			if (wildcard_case(self))
				return (true);
		}
	}
	return (false);
}
