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

#include "ft_memory.h"
#include "ms_expand.h"

#include "ms.h"

t_err	ms_expand_string_list_list_builder_feed_word(
	t_ms_expand_string_list_list_builder *self,
	t_ms_word *word
)
{
	if (ms_expand_string_list_list_builder_feed_word_part_list(
			self, &word->part_list))
		return (true);
	return (false);
}
