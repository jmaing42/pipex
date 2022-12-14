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

#include "ms_parse.h"

#include "wrap.h"

static void	free_node(t_ms_pipe_list_node *node)
{
	ms_parse_free_command(&node->command);
	wrap_free(node);
}

void	ms_parse_free_pipe_list(
	t_ms_pipe_list *pipe_list
)
{
	t_ms_pipe_list_node	*node_to_remove;

	while (pipe_list->head)
	{
		node_to_remove = pipe_list->head;
		pipe_list->head = node_to_remove->next;
		free_node(node_to_remove);
	}
	pipe_list->tail = NULL;
}
