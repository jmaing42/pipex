/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:58:08 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 20:48:41 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"
#define ARGS_SIZE 1

static char	**ms_execute_expand_args(char **out_args, int *capacity)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * 2 * *capacity);
	if (tmp == NULL)
	{
		i = -1;
		while (++i < *capacity)
			free(out_args[i]);
		free(out_args);
		return (NULL);
	}
	i = 0;
	while (i < *capacity)
	{
		tmp[i] = out_args[i];
		i++;
	}
	free(out_args);
	*capacity *= 2;
	return (tmp);
}

t_err	ms_execute_word_list(
	t_ms_word_list *word_list,
	char **out_args
)
{
	t_ms_word_list_node	*node;
	int					i;
	int					args_capacity;

	out_args = (char **)malloc(sizeof(char *) * ARGS_SIZE);
	args_capacity = ARGS_SIZE;
	i = 0;
	node = word_list->head;
	while (node)
	{
		if (i == args_capacity)
		{
			out_args = ms_execute_expand_args(out_args, &args_capacity);
			if (out_args == NULL)
				return (true);
		}
		if (ms_execute_word_part_list(&node->word->part_list, &out_args[i]))
			return (true);
		node = node->next;
		i++;
	}
	return (false);
}
