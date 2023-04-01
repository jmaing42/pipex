/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_fill_node.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:12:29 by seonlim           #+#    #+#             */
/*   Updated: 2023/04/01 13:25:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"
#include "ft_stringbuilder.h"

t_err	ms_expand_string_list_list_builder_fill_node(
	t_stringbuilder **builder,
	t_ms_expand_string_list *list
)
{
	char							*str;

	str = stringbuilder_to_string(*builder, 0);
	if (str == NULL)
		return (true);
	if (list->head == NULL && ms_expand_string_list_list_builder_add_list_node(list))
		return (true);
	list->tail->str = str;
	stringbuilder_free(*builder);
	*builder = NULL;
	return (false);
}
