/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:00:51 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 17:26:11 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ft_memory.h"
#include "ft_types.h"
#include "ms_expand.h"
#include <dirent.h>
#include <stdio.h> //test only
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

t_err	ms_expand_asterisk(
	t_ms_expand_string_list_list *string_list_list,
	t_ms_expand_string_list *out_string_list
)
{
	t_ms_expand_string_list_list_node	*node;
	t_ms_expand_string_list				dir_name_list;
	t_ms_expand_string_list_node		*dir_name_node;

	ft_memory_set(&dir_name_list, 0, sizeof(t_ms_expand_string_list));
	node = string_list_list->head;
	if (get_dir_name_list(&dir_name_list))
		return (true);
	dir_name_node = dir_name_list.head;
	while (dir_name_node)
	{
		printf("%s\n", dir_name_node->str);
		dir_name_node = dir_name_node->next;
	}
	(void)node;
	(void)out_string_list; //TODO
	ms_expand_string_list_free(&dir_name_list);
	return (false);
}
