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

t_err	ms_parse(
	const char *source,
	t_ms_program **out
)
{
	t_ms_parse_token_list		list;
	t_ms_parse_token_list_node	*head;
	t_err						result;

	if (ms_parse_tokenize(source, &list))
		return (true);
	if (!list.head)
	{
		*out = NULL;
		return (false);
	}
	head = list.head;
	result = ms_parse_parse_program(&head, out);
	ms_parse_tokenize_free(&list);
	return (result);
}
