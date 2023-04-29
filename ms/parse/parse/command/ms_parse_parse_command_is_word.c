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
	return (head->value.type == ms_parse_token_type_word
		|| (head->value.type == ms_parse_token_type_space
			&& head->next->value.type == ms_parse_token_type_word)
		|| head->value.type == ms_parse_token_type_word_quoted
		|| (head->value.type == ms_parse_token_type_space
			&& head->next->value.type == ms_parse_token_type_word_quoted)
		|| head->value.type == ms_parse_token_type_word_double_quoted
		|| (head->value.type == ms_parse_token_type_space
			&& head->next->value.type == ms_parse_token_type_word_double_quoted)
	);
}
