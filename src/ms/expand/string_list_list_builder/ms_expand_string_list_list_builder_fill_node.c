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

#include "ft_stringbuilder.h"
#include "wrap.h"

t_err	ms_expand_string_list_list_builder_fill_node(
	t_stringbuilder **builder,
	t_ms_expand_string_list *list
)
{
	char							*str;

	if (*builder == NULL)
	{
		*builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
		if (*builder == NULL)
			return (true);
	}
	str = stringbuilder_to_string(*builder, 0);
	if (str == NULL)
		return (true);
	if (ms_expand_string_list_list_builder_add_list_node(list))
	{
		wrap_free(str);
		return (true);
	}
	list->tail->str = str;
	stringbuilder_free(*builder);
	*builder = NULL;
	return (false);
}
