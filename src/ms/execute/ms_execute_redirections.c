/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:57:20 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 22:45:23 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_os_fork.h"
#include "ft_exit.h"
#include "ms.h"

#define TMP_IN_FILE "tmp_in"
#define TMP_OUT_FILE "tmp_out"


static t_err	ms_execute_redirection_list(
	t_ms_redirection_list *redirection_list,
	int *piped,
	bool is_infile
)
{
	t_ms_redirection_list_node	*node;
	char						*file_name;

	node = redirection_list->head;
	if (node == NULL)
		return (false);
	if (is_infile)
		*piped = open(TMP_IN_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		*piped = open(TMP_OUT_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (*piped < 0)
		return (true);
	while (node)
	{
		if (ms_execute_word_part_list(&node->target->part_list, &file_name))
			return (true);
		//file_name -> fd2 -> gnl -> write -> fd ?
		node = node->next;
	}
	return (false);
}

t_err	ms_execute_redirections(
	t_ms_redirections *redirections,
	int *piped_input,
	int *piped_output
)
{
	if (ms_execute_redirection_list(&redirections->in, piped_input, true))
		return (true);
	if (ms_execute_redirection_list(&redirections->out, piped_output, false))
		return (true);
	return (false);
}
