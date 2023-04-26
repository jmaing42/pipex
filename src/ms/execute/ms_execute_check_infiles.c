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

#include "ms_execute.h"

#include <stdlib.h>
#include <sys/unistd.h>

#include "ft_types.h"
#include "ms.h"
#include "wrap.h"

t_err	ms_execute_check_infiles(t_ms_command *command)
{
	t_ms_redirection_list_node	*node;
	char						*path;

	node = NULL;
	if (command->type == ms_command_type_simple)
		node = command->value.simple->redirections.in.head;
	else if (command->type == ms_command_type_compound)
		node = command->value.compound->redirections.in.head;
	while (node)
	{
		if (ms_execute_word_to_str(node->target, &path))
			return (true);
		if (wrap_access(path, R_OK) == FAIL)
		{
			wrap_free(path);
			return (true);
		}
		wrap_free(path);
		node = node->next;
	}
	return (false);
}
