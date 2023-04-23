/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_tokenize_double_quote.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/23 22:09:22 by Juyeong Maing    ###   ########.fr       */
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
		ft_stringbuilder_free(data);
		*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_ERROR, NULL};
		return (false);
	}
	if (c == '"')
	{
		if (ms_parse_tokenize_add_string_token(
				list, ms_parse_token_type_word_double_quoted, data))
			return (true);
		*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_DEFAULT, NULL};
		return (false);
	}
	if (ft_stringbuilder_append_char(data, c))
	{
		ft_stringbuilder_free(data);
		return (true);
	}
	*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_DOUBLE_QUOTE, data};
	return (false);
}
