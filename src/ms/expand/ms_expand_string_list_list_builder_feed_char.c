/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_cha        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:55:37 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/27 21:30:16 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stringbuilder.h"
#include "ms_expand.h"

static bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
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
	{
		if (ms_expand_string_list_list_builder_add_node(self))
			return (true);
	}
	else
	{
		if (stringbuilder_append_char(self->builder, ch))
			return (true);
	}
	return (false);
}
