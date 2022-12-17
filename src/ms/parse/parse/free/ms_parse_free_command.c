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

static void	free_word_list_node(t_ms_word_list_node *node)
{
	ms_parse_free_word(node->word);
	wrap_free(node);
}

static void	free_word_list(t_ms_word_list *list)
{
	t_ms_word_list_node	*node_to_remove;

	while (list->head)
	{
		node_to_remove = list->head;
		list->head = node_to_remove->next;
		free_word_list_node(node_to_remove);
	}
}

static void	free_simple(t_ms_command_simple *command)
{
	free_word_list(&command->word_list);
	ms_parse_free_redirections(&command->redirections);
}

static void	free_compound(t_ms_command_compound *command)
{
	ms_parse_free_and_or_list(&command->and_or_list);
	ms_parse_free_redirections(&command->redirections);
}

void	ms_parse_free_command(t_ms_command *command)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		free_simple(command->value.simple);
	if (command->type == MS_COMMAND_TYPE_COMPOUND)
		free_compound(command->value.compound);
}
