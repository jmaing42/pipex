/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:35:42 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/22 20:16:26 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

static void	ms_execute_compound(
	t_ms_pipe *pipe_data,
	t_ms_command_value *compound)
{
	(void)pipe_data;
	(void)compound;
}

static void	ms_execute_simple(
	t_ms_pipe *pipe_data,
	t_ms_command_value *simple)
{
	(void)pipe_data;
	(void)simple;
}

static void	ms_execute_pipe_child(
	t_ms_pipe *pipe_data,
	t_ms_pipe_list_node *pipe_node)
{
	if (pipe_node->command.type == MS_COMMAND_TYPE_COMPOUND)
		ms_execute_compound(pipe_data, &pipe_node->command.value);
	else if (pipe_node->command.type == MS_COMMAND_TYPE_SIMPLE)
		ms_execute_simple(pipe_data, &pipe_node->command.value);
}

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list, int *out_status)
{
	t_ms_pipe_list_node	*cur;
	t_ms_pipe			pipe_data;

	cur = pipe_list->head;
	while (cur)
	{
		if (pipe(pipe_data.fd) == FAIL)
			return (true);
		pipe_data.pid = fork();
		if (pipe_data.pid == FAIL)
			return (true);
		else
			ms_execute_pipe_child(&pipe_data, cur);
		// ms_execute_parent_file_control(&pipe_data);
	}
	close(pipe_data.fd_input);
	(void)out_status;
	return (false);
}
