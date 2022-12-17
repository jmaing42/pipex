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

#include "test.h"

#include <stdio.h>

t_err	print_word_list(int depth, t_ms_word_list *word_list)
{
	t_ms_word_list_node	*node;

	if (printf("%*sWordList {\n", depth, "") < 0)
		return (true);
	node = word_list->head;
	while (node)
	{
		if (print_word(depth + 1, node->word))
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}
