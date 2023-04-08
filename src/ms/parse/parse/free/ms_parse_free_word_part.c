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
	if (type == ms_word_part_unquoted)
		ms_parse_free_word_part_string_list(value.unquoted);
	if (type == ms_word_part_single_quoted)
		wrap_free(value.single_quoted);
	if (type == ms_word_part_double_quoted)
		ms_parse_free_word_part_string_list(value.double_quoted);
}
