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

#include "ft_memory.h"
#include "ft_cstring_split.h"
#include "ft_stringbuilder.h"

static size_t	get_list_len(const t_ms_expand_env_list *list)
{
	size_t						node_size;
	t_ms_expand_env_list_node	*node;

	node_size = 0;
	node = list->head;
	while (node)
	{
		++node_size;
		node = node->next;
	}
	return (node_size);
}

static char	*env_to_str(const char *key, const char *value)
{
	t_stringbuilder	*builder;
	char			*result;

	builder = ft_stringbuilder_new(STRING_BUILDER_SIZE);
	if (builder == NULL)
		return (NULL);
	if (ft_stringbuilder_append_string(builder, key))
	{
		ft_stringbuilder_free(builder);
		return (NULL);
	}
	if (ft_stringbuilder_append_char(builder, '='))
	{
		ft_stringbuilder_free(builder);
		return (NULL);
	}
	if (ft_stringbuilder_append_string(builder, value))
	{
		ft_stringbuilder_free(builder);
		return (NULL);
	}
	result = ft_stringbuilder_to_string(builder, 0);
	ft_stringbuilder_free(builder);
	return (result);
}

t_err	ms_expand_env_get_environ(char ***out_envp)
{
	const t_ms_expand_env_list *const	list = ms_expand_env_list_get();
	t_ms_expand_env_list_node			*node;
	size_t								index;

	*out_envp = ft_memory_allocate(get_list_len(list) + 1, sizeof(char *));
	if (*out_envp == NULL)
		return (true);
	index = 0;
	node = list->head;
	while (node)
	{
		(*out_envp)[index] = env_to_str(node->key, node->value);
		if ((*out_envp)[index] == NULL)
		{
			ft_cstring_split_free(*out_envp);
			return (true);
		}
		++index;
		node = node->next;
	}
	(*out_envp)[index] = NULL;
	return (false);
}
