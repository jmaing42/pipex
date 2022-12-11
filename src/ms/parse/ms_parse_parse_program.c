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

t_err	ms_parse_parse_program(
	t_ms_parse_token_list_node **mut_head,
	t_ms_program **out
)
{
	t_ms_program *const		result = wrap_malloc(sizeof(t_ms_program));

	if (!result)
		return (true);
	if (ms_parse_parse_and_or_list(mut_head, &result->and_or_list))
	{
		wrap_free(result);
		return (true);
	}
	if (!result->and_or_list.head)
	{
		wrap_free(result);
		*out = NULL;
		return (false);
	}
	ms_parse_skip_space_if_any(mut_head);
	if ((*mut_head)->value.type != MS_PARSE_TOKEN_TYPE_EOF)
	{
		ms_parse_free_program(result);
		*out = NULL;
		return (false);
	}
	*out = result;
	return (false);
}
