/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_str        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:05 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 14:36:45 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i++;
	}
	return (false);
}
