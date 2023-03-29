/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:00:51 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 15:30:17 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ms_expand.h"
#include <dirent.h>

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
		list->tail->str = dirp->d_name;
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

	node = string_list_list->head;
	if (get_dir_name_list(&dir_name_list))
		return (true);
	while (node)
	{
		node = node->next;
	}
	(void)out_string_list; //TODO
	ms_expand_string_list_free(&dir_name_list);
	return (false);
}
