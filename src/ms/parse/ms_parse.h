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

typedef enum e_ms_token_type
{
	MS_TOKEN_TYPE_SPACE,
	MS_TOKEN_TYPE_AND,
	MS_TOKEN_TYPE_OR,
	MS_TOKEN_TYPE_LEFT_CHEVRON,
	MS_TOKEN_TYPE_RIGHT_CHEVRON,
	MS_TOKEN_TYPE_LEFT_PARENTHESIS,
	MS_TOKEN_TYPE_RIGHT_PARENTHESIS,
	MS_TOKEN_TYPE_WORD,
	MS_TOKEN_TYPE_WORD_QUOTED,
	MS_TOKEN_TYPE_WORD_DOUBLE_QUOTED,
}	t_ms_token_type;

typedef struct s_ms_token
{
	t_ms_token_type	type;
	char			*word;
}	t_ms_token;

t_err	ms_parse_tokenize(const char *string, t_ms_token **out);
void	ms_parse_free_token(t_ms_token *token);

#endif
