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

#include "test.h"

#include <stdio.h>

static const char	*g_i[2] = {"File", "Heredoc"};
static const char	*g_o[2] = {"Overwrite", "Append"};

static t_err	print_in_list(int depth, t_ms_redirection_list *list)
{
	t_ms_redirection_list_node	*node;

	node = list->head;
	if (!node)
		return (false);
	if (printf("%*sInputRedirections {\n", depth, "") < 0)
		return (true);
	while (node)
	{
		if (printf("%*s%s {\n", depth + 1, "", g_i[!!node->is_special]) < 0)
			return (true);
		if (print_word(depth + 2, node->target))
			return (true);
		if (printf("%*s}\n", depth + 1, "") < 0)
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}

static t_err	print_out_list(int depth, t_ms_redirection_list *list)
{
	t_ms_redirection_list_node	*node;

	node = list->head;
	if (!node)
		return (false);
	if (printf("%*sOutputRedirections {\n", depth, "") < 0)
		return (true);
	while (node)
	{
		if (printf("%*s%s {\n", depth + 1, "", g_o[!!node->is_special]) < 0)
			return (true);
		if (print_word(depth + 2, node->target))
			return (true);
		if (printf("%*s}\n", depth + 1, "") < 0)
			return (true);
		node = node->next;
	}
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}

t_err	print_redirections(int depth, t_ms_redirections *redirections)
{
	if (printf("%*sInput {\n", depth, "") < 0)
		return (true);
	if (print_in_list(depth + 1, &redirections->in))
		return (true);
	if (printf("%*s}\n%*sOutput {\n", depth, "", depth, "") < 0)
		return (true);
	if (print_out_list(depth + 1, &redirections->out))
		return (true);
	if (printf("%*s}\n", depth, "") < 0)
		return (true);
	return (false);
}
