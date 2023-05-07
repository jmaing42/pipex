/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipe_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/06 20:13:06 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_os_fork.h"
#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ft_memory.h"
#include "ms.h"
#include "wrap.h"

static t_err	redirect_in_out(t_ms_execute_pipe_info *info)
{
	if (!info->is_first)
	{
		if (wrap_dup2(info->previous_pipe_read, STDIN_FILENO) < 0)
			return (true);
		wrap_close(info->previous_pipe_read);
	}
	if (!info->is_last)
	{
		if (wrap_dup2(info->pipe_write, STDOUT_FILENO) < 0)
			return (true);
	}
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
	ms_execute_set_signals(pid);
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
	if (!info->is_first)
		wrap_close(info->previous_pipe_read);
	wrap_close(info->pipe_write);
	info->previous_pipe_read = wrap_dup(info->pipe_read);
	if (info->previous_pipe_read < 0)
		return (true);
	wrap_close(info->pipe_read);
	return (false);
}

static t_err	wait_all_and_free_pid_list(t_ms_execute_pid_list *list)
{
	t_ms_execute_pid_list_node	*node;
	t_ms_execute_pid_list_node	*next;
	t_err						result;
	int							stat;

	if (list->tail->pid == CHILD_PID)
		wrap_exit(EXIT_FAILURE);
	stat = -1;
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
	ms_execute_globals()->exit_status = WEXITSTATUS(stat);
	if (WIFSIGNALED(stat))
		ms_execute_globals()->exit_status = 128 + WTERMSIG(stat);
	return (result);
}

t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_ms_execute_pipe_info			info;
	t_ms_pipe_list_node				*node;

	if (ms_execute_builtin_check(pipe_list))
	{
		ms_execute_builtin_run(&pipe_list->head->command);
		return (false);
	}
	ft_memory_set(&info, 0, sizeof(t_ms_execute_pipe_info));
	info.is_first = true;
	node = pipe_list->head;
	while (node)
	{
		if (node->next == NULL)
			info.is_last = true;
		if (pipe_and_fork(&info))
			return (wait_all_and_free_pid_list(&info.pid_list));
		if (info.pid_list.tail->pid == CHILD_PID)
			ms_execute_command(&node->command, info.is_first, info.is_last);
		if (info.is_first)
			info.is_first = false;
		node = node->next;
	}
	wrap_close(info.previous_pipe_read);
	return (wait_all_and_free_pid_list(&info.pid_list));
}
