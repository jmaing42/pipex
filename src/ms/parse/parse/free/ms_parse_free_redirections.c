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

#include "ms.h"
#include "ms_parse.h"

#include "wrap.h"

static void	free_node(t_ms_redirection_list_node *node)
{
	ms_parse_free_word(node->target);
	wrap_free(node);
}

static void	free_list(t_ms_redirection_list *list)
{
	t_ms_redirection_list_node	*node_to_remove;

	while (list->head)
	{
		node_to_remove = list->head;
		list->head = node_to_remove->next;
		free_node(node_to_remove);
	}
	list->tail = NULL;
}

void	ms_parse_free_redirections(t_ms_redirections *redirections)
{
	free_list(&redirections->in);
	free_list(&redirections->out);
}
