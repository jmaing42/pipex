/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_redirections_word_to_str.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/08 17:57:46 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ms_execute.h"
#include "wrap.h"

static void	free_args(char **args)
{
	size_t	index;

	if (args[0] == NULL)
	{
		wrap_free(args);
		return ;
	}
	index = 1;
	while (args[index])
	{
		wrap_free(args[index]);
		++index;
	}
	wrap_free(args);
}

t_err	ms_execute_word_to_str(
	t_ms_word *word,
	char **out_path
)
{
	t_ms_word_list		list;
	t_ms_word_list_node	*node;
	char				**args;

	node = ft_memory_allocate(1, sizeof(t_ms_word_list_node));
	if (node == NULL)
		return (true);
	node->word = word;
	list.head = node;
	list.tail = node;
	if (ms_expand(&list, &args))
	{
		wrap_free(node);
		return (true);
	}
	*out_path = args[0];
	wrap_free(node);
	free_args(args);
	return (false);
}
