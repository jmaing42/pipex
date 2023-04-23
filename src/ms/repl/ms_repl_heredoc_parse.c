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

#include "ms_repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>

#include "ms.h"
#include "ms_execute.h"
#include "wrap.h"
#include "ft_memory.h"

static t_err	add_node(t_ms_repl_string_list *list, char *str)
{
	t_ms_repl_string_list_node	*new_node;

	new_node = ft_memory_allocate(1, sizeof(t_ms_repl_string_list_node));
	if (new_node == NULL)
		return (true);
	new_node->str = str;
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = list->tail->next;
	}
	return (false);
}

static t_err	replace_redirection_list(
	t_ms_redirection_list *list,
	t_ms_repl_string_list *tmp_list,
	bool *is_heredoc
)
{
	t_ms_redirection_list_node	*node;
	char						*file_name;
	char						*limiter;

	node = list->head;
	while (node)
	{
		if (node->is_special)
		{
			*is_heredoc = true;
			if (ms_tmpname_find(&file_name))
				return (true);
			if (add_node(tmp_list, file_name))
				return (true);
			if (ms_execute_word_to_str(node->target, &limiter))
				return (true);
			if (ms_repl_heredoc_make_tmpfile(node, file_name, limiter))
				return (true);
			wrap_free(limiter);
		}
		node = node->next;
	}
	return (false);
}

static t_err	replace_pipe_list(
	t_ms_pipe_list *list,
	t_ms_repl_string_list *tmp_list,
	bool *is_heredoc
)
{
	t_ms_pipe_list_node	*node;

	node = list->head;
	while (node)
	{
		if (node->command.type == ms_command_type_compound)
		{
			if (replace_redirection_list(
					&node->command.value.compound->redirections.in
					, tmp_list, is_heredoc))
				return (true);
		}
		else if (node->command.type == ms_command_type_simple)
		{
			if (replace_redirection_list(
					&node->command.value.simple->redirections.in
					, tmp_list, is_heredoc))
				return (true);
		}
		node = node->next;
	}
	return (false);
}

static t_err	replace_and_or_list(
	t_ms_and_or_list *list,
	t_ms_repl_string_list *tmp_list,
	bool *is_heredoc
)
{
	t_ms_and_or_list_node	*node;

	node = list->head;
	while (node)
	{
		if (replace_pipe_list(&node->pipe_list, tmp_list, is_heredoc))
			return (true);
		node = node->next;
	}
	return (false);
}

t_err	ms_repl_heredoc_parse(
	t_ms_program *mut,
	t_ms_repl_string_list *out_tmp_files,
	bool *out_is_heredoc
)
{
	if (replace_and_or_list(&mut->and_or_list, out_tmp_files, out_is_heredoc))
		return (true);
	return (false);
}
