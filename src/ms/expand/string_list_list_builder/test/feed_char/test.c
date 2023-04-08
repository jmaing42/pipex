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

#include "test.h"

#include <stdio.h>

#include "ft_types.h"
#include "ft_stringbuilder.h"
#include "ms_expand.h"

t_err	print_builder(t_ms_expand_string_list_list_builder *builder)
{
	t_ms_expand_string_list_list_node	*ll_node;
	t_ms_expand_string_list_node		*node;

	ll_node = builder->list.head;
	while (ll_node)
	{
		node = ll_node->list.head;
		if (puts("* * *") == EOF)
			return (true);
		while (node)
		{
			if (printf("\t%s\n", node->str) < 0)
				return (true);
			node = node->next;
		}
		ll_node = ll_node->next;
	}
	printf("%s\n", ft_stringbuilder_to_string(builder->builder, 0));
	return (false);
}
