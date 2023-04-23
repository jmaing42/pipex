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

#include "ms_builtin.h"

#include <stdio.h>
#include <stdlib.h>

#include "ms_execute.h"
#include "ms_expand.h"

void	ms_builtin_env(void)
{
	t_ms_expand_env_list *const	list = ms_expand_env_list_get();
	t_ms_expand_env_list_node	*node;

	node = list->head;
	while (node)
	{
		if (printf("%s=%s\n", node->key, node->value) == FAIL)
		{
			perror("minishell env");
			ms_execute_globals()->exit_status = EXIT_FAILURE;
			return ;
		}
		node = node->next;
	}
	ms_execute_globals()->exit_status = EXIT_SUCCESS;
}
