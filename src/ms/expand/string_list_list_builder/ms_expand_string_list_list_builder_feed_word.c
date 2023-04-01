/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_feed_word.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/01 12:38:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ms_expand.h"

#include "ms.h"

t_err	ms_expand_string_list_list_builder_feed_word(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word *word
)
{
	if (ms_expand_string_list_list_builder_add_list_node(&self->list))
		return (true);
	if (ms_expand_string_list_list_builder_feed_word_part_list(
			self, &word->part_list))
		return (true);
	return (false);
}
