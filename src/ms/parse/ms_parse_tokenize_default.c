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

#include "ft_stringbuilder.h"
#include "ms_parse.h"

typedef t_ms_parse_tokenize_state	t_s;

static t_err	special_token(
	char c,
	t_ms_parse_token_list *list,
	t_ms_parse_tokenize_state *out_next_state
)
{
	*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_DEFAULT, NULL};
	return (
		(!c && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_EOF))
		|| (c == '&' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_AND))
		|| (c == '|' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_OR))
		|| (c == '<' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON))
		|| (c == '>' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON))
		|| (c == '(' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS))
		|| (c == ')' && ms_parse_tokenize_add_simple_token(
				list, MS_PARSE_TOKEN_TYPE_RIGHT_PARENTHESIS))
	);
}

static t_err	transition_to_word(
	char c,
	t_ms_parse_tokenize_state *out_next_state
)
{
	t_stringbuilder *const	next_state_data = new_stringbuilder(1024);

	if (!next_state_data)
		return (true);
	if (stringbuilder_append_char(next_state_data, c))
	{
		stringbuilder_free(next_state_data);
		return (true);
	}
	out_next_state->data = next_state_data;
	out_next_state->state = MS_PARSE_TOKENIZE_STATE_WORD;
	return (false);
}

static t_err	transition_to_quote(
	t_ms_parse_tokenize_state *out_next_state,
	bool is_double_quote
)
{
	t_stringbuilder *const	next_state_data = new_stringbuilder(1024);

	if (!next_state_data)
		return (true);
	out_next_state->data = next_state_data;
	out_next_state->state = MS_PARSE_TOKENIZE_STATE_QUOTE;
	if (is_double_quote)
		out_next_state->state = MS_PARSE_TOKENIZE_STATE_DOUBLE_QUOTE;
	return (false);
}

t_err	ms_parse_tokenize_state_default(
	char c,
	t_ms_parse_token_list *list,
	t_stringbuilder *data,
	t_ms_parse_tokenize_state *out_next_state
)
{
	(void)data;
	*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_ERROR, NULL};
	if (!c
		|| c == '&' || c == '|' || c == '<' || c == '>' || c == '(' || c == ')')
		return (special_token(c, list, out_next_state));
	else if (c == ' ' || c == '\n' || c == '\t')
		*out_next_state = (t_s){MS_PARSE_TOKENIZE_STATE_SPACE, NULL};
	else if (c == '\'')
		return (transition_to_quote(out_next_state, false));
	else if (c == '"')
		return (transition_to_quote(out_next_state, true));
	else
		return (transition_to_word(c, out_next_state));
	return (false);
}
