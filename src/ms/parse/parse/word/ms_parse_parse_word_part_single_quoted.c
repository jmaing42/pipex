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

#include "ft_cstring.h"
#include "wrap.h"

t_err	ms_parse_parse_word_part_single_quoted(
	const char *data,
	t_ms_word_part_single_quoted **out
)
{
	t_ms_word_part_single_quoted *const	result
		= wrap_malloc(sizeof(t_ms_word_part_single_quoted));

	if (!result || ft_cstring_duplicate(data, result))
	{
		wrap_free(result);
		return (true);
	}
	*out = result;
	return (false);
}
