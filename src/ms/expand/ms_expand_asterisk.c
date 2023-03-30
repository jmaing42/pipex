/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:00:51 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/30 15:54:57 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ft_memory.h"
#include "ft_types.h"
#include "ms_expand.h"
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>

static t_err	get_dir_name_list(t_ms_expand_string_list *list)
{
	DIR				*dp;
	struct dirent	*dirp;

	dp = opendir(".");
	if (dp == NULL)
		return (true);
	dirp = readdir(dp);
	while (dirp)
	{
		if (ms_expand_string_list_node_add(list))
			return (true);
		if (ft_cstring_duplicate(dirp->d_name, &list->tail->str))
			return (true);
		dirp = readdir(dp);
	}
	closedir(dp);
	return (false);
}

static bool	is_possible(
	t_ms_expand_string_list *cmd_list,
	char *name
)
{
	t_ms_expand_string_list_node	*node;

	node = cmd_list->head;
	while (node)
	{
		name = ms_expand_strnstr(name, node->str, -1);
		if (name == NULL)
			return (false);
		node = node->next;
	}
	return (true);
}

static t_err	apply_wildcard(
	t_ms_expand_string_list *cmd_list,
	t_ms_expand_string_list *out_string_list
)
{
	t_ms_expand_string_list				dir_name_list;
	t_ms_expand_string_list_node		*name_node;

	ft_memory_set(&dir_name_list, 0, sizeof(t_ms_expand_string_list));
	if (get_dir_name_list(&dir_name_list))
		return (true);
	name_node = dir_name_list.head;
	while (name_node)
	{
		if (is_possible(cmd_list, name_node->str))
		{
			if (ms_expand_string_list_node_add(out_string_list))
				return (true);
			if (ft_cstring_duplicate(
					name_node->str, &out_string_list->tail->str))
				return (true);
		}
		name_node = name_node->next;
	}
	ms_expand_string_list_free(&dir_name_list);
	return (false);
}

t_err	ms_expand_asterisk(
	t_ms_expand_string_list_list *string_list_list,
	t_ms_expand_string_list *out_string_list
)
{
	t_ms_expand_string_list_list_node	*node;

	node = string_list_list->head;
	while (node)
	{
		if (node->list.head == node->list.tail)
		{
			if (ms_expand_string_list_node_add(out_string_list))
				return (true);
			if (ft_cstring_duplicate(
					node->list.head->str, &out_string_list->tail->str))
				return (true);
		}
		else
			if (apply_wildcard(&node->list, out_string_list))
				return (true);
		node = node->next;
	}
	return (false);
}
