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

#ifndef MS_PARSE_H
# define MS_PARSE_H

# include "ms.h"

typedef enum e_ms_parse_token_type
{
	MS_PARSE_TOKEN_TYPE_EOF,
	MS_PARSE_TOKEN_TYPE_SPACE,
	MS_PARSE_TOKEN_TYPE_AND,
	MS_PARSE_TOKEN_TYPE_OR,
	MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON,
	MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON,
	MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS,
	MS_PARSE_TOKEN_TYPE_RIGHT_PARENTHESIS,
	MS_PARSE_TOKEN_TYPE_WORD,
	MS_PARSE_TOKEN_TYPE_WORD_QUOTED,
	MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED,
}	t_ms_parse_token_type;

typedef struct s_ms_parse_token
{
	t_ms_parse_token_type	type;
	char					*word;
}	t_ms_parse_token;

t_err	ms_parse_tokenize(const char *string, t_ms_parse_token **out);
void	ms_parse_free_token(t_ms_parse_token *token);

# define MS_PARSE_TOKENIZER_STATE_ERROR -1
# define MS_PARSE_TOKENIZER_STATE_DEFAULT 0
# define MS_PARSE_TOKENIZER_STATE_SPACE 1
# define MS_PARSE_TOKENIZER_STATE_WORD 2
# define MS_PARSE_TOKENIZER_STATE_QUOTE 3
# define MS_PARSE_TOKENIZER_STATE_DOUBLE_QUOTE 4

typedef struct s_ms_parse_tokenizer_state
{
	int		state;
	char	*data;
}	t_ms_parse_tokenizer_state;

typedef t_err	(*t_ms_parse_tokenize_function)(
					char c,
					t_ms_parse_token *list,
					void *data,
					t_ms_parse_tokenizer_state *out_next_state);

t_err	ms_parse_tokenize_default(
			char c,
			t_ms_parse_token *list,
			void *data,
			t_ms_parse_tokenizer_state *out_next_state);

t_err	ms_parse_tokenize_space(
			char c,
			t_ms_parse_token *list,
			void *data,
			t_ms_parse_tokenizer_state *out_next_state);

t_err	ms_parse_tokenize_word(
			char c,
			t_ms_parse_token *list,
			void *data,
			t_ms_parse_tokenizer_state *out_next_state);

t_err	ms_parse_tokenize_quote(
			char c,
			t_ms_parse_token *list,
			void *data,
			t_ms_parse_tokenizer_state *out_next_state);

t_err	ms_parse_tokenize_double_quote(
			char c,
			t_ms_parse_token *list,
			void *data,
			t_ms_parse_tokenizer_state *out_next_state);

#endif
