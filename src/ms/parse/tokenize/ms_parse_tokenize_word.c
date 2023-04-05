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

t_err	ms_parse_tokenize_state_word(
	char c,
	t_ms_parse_token_list *list,
	t_stringbuilder *data,
	t_ms_parse_tokenize_state *out_next_state
)
{
	(void)data;
	if (!c || c == ' ' || c == '\n' || c == '\t' || c == '\'' || c == '"'
		|| c == '&' || c == '|' || c == '<' || c == '>' || c == '(' || c == ')')
	{
		if (ms_parse_tokenize_add_string_token(
				list, MS_PARSE_TOKEN_TYPE_WORD, data))
			return (true);
		return (ms_parse_tokenize_state_default(c, list, NULL, out_next_state));
	}
	if (ft_stringbuilder_append_char(data, c))
	{
		ft_stringbuilder_free(data);
		return (true);
	}
	*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_WORD, data};
	return (false);
}
