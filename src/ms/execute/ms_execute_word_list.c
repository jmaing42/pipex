/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_word_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:58:08 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/23 22:15:21 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"

t_err	ms_execute_word_list(
	t_ms_word_list *word_list,
	int *piped_in,
	int *piped_out
)
{
	t_ms_word_list_node	*node;

	node = word_list->head;
	while (node)
	{
		if (ms_execute_word_part_list(&node->word->part_list))
			return (true);
		node = node->next;
	}
	(void)piped_in; (void)piped_out;
	return (false);
}
