/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:20 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/22 20:16:30 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

t_err	ms_execute_and_or_list(t_ms_and_or_list *and_or_list, int *out_status)
{
	t_ms_and_or_list_node	*cur;			

	cur = and_or_list->head;
	out_status = 0;
	while (cur)
	{
		if (cur->is_and && !out_status)
		{
			if (ms_execute_pipe_list(&cur->pipe_list, out_status))
				return (true);
		}
		else if (!cur->is_and && !!out_status)
		{
			if (ms_execute_pipe_list(&cur->pipe_list, out_status))
				return (true);
		}
		cur = cur->next;
	}
	return (false);
}

t_err	ms_execute_program(t_ms_program *program, int *out_status)
{
	return (ms_execute_and_or_list(&program->and_or_list, out_status));
}

t_err	ms_execute(t_ms_program *program, int *out_status)
{
	const t_err	result = ms_execute_program(program, out_status);

	if (result)
	{
		*out_status = 1;
		return (true);
	}
	return (false);
}
