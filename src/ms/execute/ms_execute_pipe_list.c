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

#include "ft_os_fork.h"
#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ft_memory.h"
#include "ms.h"
#include "wrap.h"

static t_err	redirect_in_out(t_ms_execute_pipe_info *info)
{
	if (info->pid_list.head != info->pid_list.tail)
	{
		if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO) < 0)
			return (true);
		wrap_close(info->previous_pipe_read);
	}
	if (!info->is_last && wrap_dup2(info->pipe_write, STDOUT_FILENO) < 0)
		return (true);
	wrap_close(info->pipe_read);
	wrap_close(info->pipe_write);
	return (false);
}

static t_err	add_pid_node(t_ms_execute_pid_list *pid_list)
{
	t_ms_execute_pid_list_node	*new_node;
	pid_t						pid;

	if (ft_os_fork(&pid))
		return (true);
	new_node = ft_memory_allocate(1, sizeof(t_ms_execute_pid_list_node));
	if (new_node == NULL)
		return (true);
	new_node->pid = pid;
	if (pid_list->head == NULL)
	{
		pid_list->head = new_node;
		pid_list->tail = new_node;
	}
	else
	{
		pid_list->tail->next = new_node;
		pid_list->tail = pid_list->tail->next;
	}
	return (false);
}

static t_err	pipe_and_fork(t_ms_execute_pipe_info *info)
{
	if (ft_os_pipe(&info->pipe_write, &info->pipe_read))
		return (true);
	if (add_pid_node(&info->pid_list))
		return (true);
	if (info->pid_list.tail->pid == CHILD_PID)
	{
		if (redirect_in_out(info))
			wrap_exit(EXIT_FAILURE);
		return (false);
	}
	if (info->pid_list.head == info->pid_list.tail)
		wrap_close(info->previous_pipe_read);
	info->previous_pipe_read = wrap_dup(info->pipe_read);
	if (info->previous_pipe_read < 0)
		return (true);
	wrap_close(info->pipe_write);
	return (false);
}

static t_err	wait_all(t_ms_execute_pid_list *list)
{
	t_ms_execute_pid_list_node	*node;
	t_ms_execute_pid_list_node	*next;
	t_err						result;
	int							stat;

	result = false;
	node = list->head;
	while (node)
	{
		next = node->next;
		if (wrap_waitpid(node->pid, &stat, 0) == FAIL)
			result = true;
		free(node);
		node = next;
	}
	return (result);
}

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_ms_execute_pipe_info			info;
	t_ms_pipe_list_node				*node;

	ft_memory_set(&info, 0, sizeof(t_ms_execute_cmd_pipe_info));
	node = pipe_list->head;
	while (node)
	{
		if (node->next == NULL)
			info.is_last = true;
		if (pipe_and_fork(&info))
			return (true);
		if (info.pid_list.tail->pid == CHILD_PID)
		{
			if (ms_execute_command(&node->command))
				return (true);
		}
		node = node->next;
	}
	return (wait_all(&info.pid_list));
}
