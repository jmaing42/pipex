/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_check_infiles.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/08 17:48:37 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ms_execute.h"

#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>

#include "ft_types.h"
#include "ms.h"
#include "wrap.h"

void	ms_execute_check_infiles(t_ms_command *command)
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
			ms_execute_fd_exit(STDERR_FILENO, INTERNAL_ERROR);
		if (path == NULL)
			ms_execute_fd_exit(STDERR_FILENO, NO_MATCH);
		if (wrap_access(path, R_OK) == FAIL)
		{
			wrap_free(path);
			ms_execute_fd_exit(STDERR_FILENO, NO_MATCH);
		}
		wrap_free(path);
		node = node->next;
	}
}
