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

#include "ft_io.h"
#include "ms_execute.h"
#include "ms_expand.h"

static	t_err	print(char *message, int fd)
{
	if (ft_puts(fd, message))
	{
		perror("minishell env");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return (true);
	}
	return (false);
}

void	ms_builtin_env(int fd)
{
	t_ms_expand_env_list *const	list = ms_expand_env_list_get();
	t_ms_expand_env_list_node	*node;

	ms_execute_globals()->exit_status = EXIT_SUCCESS;
	node = list->head;
	while (node)
	{
		if (print(node->key, fd))
			return ;
		if (print("=", fd))
			return ;
		if (print(node->value, fd))
			return ;
		node = node->next;
	}
}
