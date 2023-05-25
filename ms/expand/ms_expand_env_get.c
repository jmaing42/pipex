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

#include "ft_cstring.h"
#include "ms_expand.h"

const char	*ms_expand_env_get(const char *key)
{
	t_ms_expand_env_list		*list;
	t_ms_expand_env_list_node	*node;

	list = ms_expand_env_list_get();
	node = list->head;
	while (node)
	{
		if (ft_cstring_equals(key, node->key))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
