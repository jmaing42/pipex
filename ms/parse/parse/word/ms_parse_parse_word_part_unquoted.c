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

t_err	ms_parse_parse_word_part_unquoted(
	const char *data,
	t_ms_word_part_string_list **out
)
{
	t_ms_word_part_string_list *const	result
		= wrap_malloc(sizeof(t_ms_word_part_string_list));

	if (!result)
	{
		wrap_free(result);
		return (true);
	}
	*result = (t_ms_word_part_string_list){NULL, NULL};
	if (ms_parse_parse_word_part_fill(data, result))
	{
		ms_parse_free_word_part_string_list(result);
		return (true);
	}
	*out = result;
	return (false);
}
