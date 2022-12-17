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

t_err	print_pipe_list(int depth, t_ms_pipe_list *pipe_list)
{
	t_ms_pipe_list_node	*node;

	if (printf("%*sPipeList {\n", depth, "") < 0)
		return (true);
	node = pipe_list->head;
	while (node)
	{
		if (print_command(depth + 1, &node->command))
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}
