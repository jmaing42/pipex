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

bool	ms_parse_parse_command_is_word(t_ms_parse_token_list_node *head)
{
	return (head->value.type == MS_PARSE_TOKEN_TYPE_WORD
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD)
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
		|| head->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED
		|| (head->value.type == MS_PARSE_TOKEN_TYPE_SPACE
			&& head->next->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
	);
}
