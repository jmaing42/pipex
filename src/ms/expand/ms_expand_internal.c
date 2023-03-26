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

#include "ms_expand.h"

#include "ft_types.h"
#include "ms.h"

t_err	ms_expand_internal(
	t_ms_word_list *list,
	t_ms_expand_string_list *out
)
{
	t_ms_expand_string_list_list			string_list_list;
	t_ms_expand_string_list_list_builder	builder;
	t_err									result;

	ms_expand_string_list_list_builder_init(&builder);
	if (
		ms_expand_string_list_list_builder_feed_word_list(
			&builder, list)
		|| ms_expand_string_list_list_builder_finalize(
			&builder, &string_list_list)
	)
	{
		ms_expand_string_list_list_builder_free(&builder);
		return (true);
	}
	result = ms_expand_asterisk(string_list_list, out);
	ms_expand_string_list_list_free(string_list_list);
	return (result);
}
