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

typedef t_ms_parse_tokenize_state	t_s;

t_err	ms_parse_tokenize_state_double_quote(
	char c,
	t_ms_parse_token_list *list,
	t_stringbuilder *data,
	t_ms_parse_tokenize_state *out_next_state
)
{
	(void)data;
	if (!c)
	{
		stringbuilder_free(data);
		return (true);
	}
	if (c == '"')
	{
		if (ms_parse_tokenize_add_string_token(
				list, MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED, data))
			return (true);
		*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_DEFAULT, NULL};
		return (false);
	}
	if (stringbuilder_append_char(data, c))
	{
		stringbuilder_free(data);
		return (true);
	}
	*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_DOUBLE_QUOTE, data};
	return (false);
}
