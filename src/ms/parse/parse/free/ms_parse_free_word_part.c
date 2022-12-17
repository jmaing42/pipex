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

#include "ms_parse.h"

#include "wrap.h"

void	ms_parse_free_word_part(
	t_ms_word_part_type type,
	t_ms_word_part_value value
)
{
	if (type == MS_WORD_PART_UNQUOTED)
		ms_parse_free_word_part_string_list(value.unquoted);
	if (type == MS_WORD_PART_SINGLE_QUOTED)
		wrap_free(value.single_quoted);
	if (type == MS_WORD_PART_DOUBLE_QUOTED)
		ms_parse_free_word_part_string_list(value.double_quoted);
}
