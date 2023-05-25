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

static const t_ms_parse_tokenize_function	g_state_functions[] = {
	ms_parse_tokenize_state_default,
	ms_parse_tokenize_state_space,
	ms_parse_tokenize_state_word,
	ms_parse_tokenize_state_quote,
	ms_parse_tokenize_state_double_quote,
};

t_err	ms_parse_tokenize(const char *str, t_ms_parse_token_list *out)
{
	t_ms_parse_tokenize_state	current_state;
	size_t						i;

	current_state.state = MS_PARSE_TOKENIZE_STATE_DEFAULT;
	current_state.data = NULL;
	*out = (t_ms_parse_token_list){NULL, NULL};
	i = -1;
	while (current_state.state != MS_PARSE_TOKENIZE_STATE_ERROR
		&& (i++ == (size_t)-1 || str[i - 1]))
	{
		if (g_state_functions[current_state.state](
			str[i], out, current_state.data, &current_state))
		{
			ms_parse_tokenize_free(out);
			return (true);
		}
	}
	if (current_state.state == MS_PARSE_TOKENIZE_STATE_ERROR)
	{
		ms_parse_tokenize_free(out);
		*out = (t_ms_parse_token_list){NULL, NULL};
	}
	return (false);
}
