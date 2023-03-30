/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/30 19:44:24 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include "ft_types.h"
#include "ft_memory.h"
#include "ft_cstring.h"
#include "ft_cstring_split.h"

#include "ms.h"

static size_t	string_list_length(t_ms_expand_string_list list)
{
	size_t							result;
	t_ms_expand_string_list_node	*tmp;

	result = 0;
	tmp = list.head;
	while (tmp)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

static t_err	allocate_and_fill(
	t_ms_expand_string_list string_list,
	char ***out
)
{
	const size_t					length
		= string_list_length(string_list);
	char **const					result
		= ft_memory_allocate(length + 1, sizeof(char *));
	t_ms_expand_string_list_node	*tmp;
	size_t							i;

	if (!result)
		return (true);
	i = 0;
	tmp = string_list.head;
	while (tmp)
	{
		if (ft_cstring_duplicate(tmp->str, &result[i++]))
		{
			ft_cstring_split_free(result);
			return (true);
		}
		tmp = tmp->next;
	}
	*out = result;
	return (false);
}

t_err	ms_expand(
	t_ms_word_list *list,
	char ***out_argv
)
{
	t_ms_expand_string_list	string_list;
	t_err					result;

	ft_memory_set(&string_list, 0, sizeof(t_ms_expand_string_list));
	if (ms_expand_internal(list, &string_list))
		return (true);
	result = allocate_and_fill(string_list, out_argv);
	ms_expand_string_list_free(&string_list);
	return (result);
}
