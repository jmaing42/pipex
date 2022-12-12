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

bool	ms_parse_parse_command_is_redirection(
	t_ms_parse_token_list_node **mut_head
)
{
	ms_parse_skip_space_if_any(mut_head);
	return (((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& ms_parse_parse_command_is_word((*mut_head)->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& (*mut_head)->next->value.type
			== MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON
			&& ms_parse_parse_command_is_word((*mut_head)->next->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& ms_parse_parse_command_is_word((*mut_head)->next))
		|| ((*mut_head)->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& (*mut_head)->next->value.type
			== MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON
			&& ms_parse_parse_command_is_word((*mut_head)->next->next))
	);
}
