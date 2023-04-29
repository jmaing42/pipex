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

#include "wrap.h"

t_err	ms_parse_parse_command(
	t_ms_parse_token_list_node **mut_head,
	t_ms_command *out
)
{
	t_ms_redirections	redirections;

	redirections = (t_ms_redirections){{NULL, NULL}, {NULL, NULL}};
	while (ms_parse_parse_command_is_redirection(mut_head))
	{
		if (ms_parse_parse_command_add_redirection(mut_head, &redirections))
			return (true);
		if (!redirections.in.head && !redirections.out.head)
		{
			*out = (t_ms_command){ms_command_type_invalid, {NULL}};
			return (false);
		}
	}
	if ((*mut_head)->value.type == ms_parse_token_type_left_parenthesis)
		return (ms_parse_parse_command_compound(mut_head, redirections, out));
	if (ms_parse_parse_command_is_word(*mut_head))
		return (ms_parse_parse_command_simple(mut_head, redirections, out));
	ms_parse_free_redirections(&redirections);
	*out = (t_ms_command){ms_command_type_invalid, {NULL}};
	return (false);
}
