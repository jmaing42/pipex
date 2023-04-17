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

#include "ft_memory.h"
#include "ms_execute.h"
#include "wrap.h"

t_err	ms_execute_word_to_str(
	t_ms_word *word,
	char **out_path
)
{
	t_ms_word_list		list;
	t_ms_word_list_node	*node;
	char				**args;

	node = ft_memory_allocate(1, sizeof(t_ms_word_list_node));
	if (node == NULL)
		return (true);
	node->word = word;
	list.head = node;
	list.tail = node;
	if (ms_expand(&list, &args))
	{
		wrap_free(node);
		return (true);
	}
	*out_path = args[0];
	wrap_free(node);
	wrap_free(args);
	return (false);
}
