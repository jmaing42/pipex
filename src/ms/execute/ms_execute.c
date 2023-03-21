/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:20 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/20 22:40:55 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe)
{
	t_ms_pipe_list_node	*cur;
	t_ms_pipe			pipe_data;

	cur = pipe->head;
	while (cur)
	{
		if (pipe(data->fd) == FAIL)
	}
}

int	ms_execute_and_or_list(t_ms_and_or_list *and_or)
{
	t_ms_and_or_list_node	*cur;			
	int						exit_status;

	cur = and_or->head;
	exit_status = 0;
	while (cur)
	{
		if (cur->is_and && !exit_status)
			exit_status = ms_execute_and_or_list(cur->pipe_list);
		else if (!cur->is_and && exit_status)
			exit_status = ms_execute_and_or_list(cur->pipe_list);
		cur = cur->next;
	}
	return (exit_status);
}

int	ms_execute_program(t_ms_program *program)
{
	return (ms_execute_and_or_list(program->and_or_list));
}

int	ms_execute(t_ms_program *program)
{
	return (ms_execute_program(program));
}
