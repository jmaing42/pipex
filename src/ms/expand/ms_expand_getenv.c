/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_getenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:55:55 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 15:33:18 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ms_expand.h"

const char	*ms_expand_getenv(const char *key)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*node;

	list = ms_expand_env_list_get();
	node = list->head;
	while (node)
	{
		if (!ft_cstring_compare(key, node->key))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
