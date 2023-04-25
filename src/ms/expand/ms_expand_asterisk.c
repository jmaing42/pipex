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
		if (ft_cstring_equals(dirp->d_name, ".")
			|| ft_cstring_equals(dirp->d_name, ".."))
		{
			dirp = readdir(dp);
			continue ;
		}
		if (ms_expand_string_list_list_builder_add_list_node(list))
			return (true);
		if (ft_cstring_duplicate(dirp->d_name, &list->tail->str))
			return (true);
		dirp = readdir(dp);
	}
	closedir(dp);
	return (false);
}

static bool	is_possible_name(
	t_ms_expand_string_list *cmd_list,
	char *name
)
{
	t_ms_expand_string_list_node	*node;

	node = cmd_list->head;
	if (ft_cstring_equals(node->str, ".") && name[0] != '.')
		return (false);
	if (!ft_cstring_equals(node->str, ".") && name[0] == '.')
		return (false);
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
	t_ms_expand_string_list			dir_name_list;
	t_ms_expand_string_list_node	*name_node;

	ft_memory_set(&dir_name_list, 0, sizeof(t_ms_expand_string_list));
	if (get_dir_name_list(&dir_name_list))
	{
		ms_expand_string_list_free(&dir_name_list);
		return (true);
	}
	name_node = dir_name_list.head;
	while (name_node)
	{
		if (is_possible_name(cmd_list, name_node->str))
		{
			if (ms_expand_string_list_list_builder_add_list_node(
					out_string_list))
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

static t_err	ms_expand_asterisk_internal(
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
			if (ms_expand_string_list_list_builder_add_list_node(
					out_string_list))
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

t_err	ms_expand_asterisk(
	t_ms_expand_string_list_list *string_list_list,
	t_ms_expand_string_list *out_string_list
)
{
	const t_err	result
		= ms_expand_asterisk_internal(string_list_list, out_string_list);

	if (result)
		ms_expand_string_list_free(out_string_list);
	return (result);
}
