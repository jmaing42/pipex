/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_str        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:05 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 22:18:53 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"
#include "ms.h"
#include "ms_expand.h"

t_err	ms_expand_string_list_list_builder_feed_string(
	t_ms_expand_string_list_list_builder *self,
	const char *str,
	t_ms_word_part_type type
)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ms_expand_string_list_list_builder_feed_char(
				self, str[i], type))
			return (true);
		if (str[i] == '*' && str[i + 1] == '\0')
		{
			if (self->builder == NULL)
				self->builder = new_stringbuilder(STRING_BUILDER_SIZE);
			if (self->builder == NULL)
				return (true);
			if (ms_expand_string_list_node_add(&self->list.tail->list)
				|| ms_expand_string_list_list_builder_fill_node(
					&self->builder, &self->list.tail->list)
				|| ms_expand_string_list_list_node_add(&self->list))
				return (true);
		}
		i++;
	}
	return (false);
}
