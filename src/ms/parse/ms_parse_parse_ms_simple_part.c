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

#include "ft_cstring.h"
#include "ms_parse.h"

#include <stdlib.h>

static size_t	count(t_ms_parse_token_list_node **head)
{
	size_t						result;
	t_ms_parse_token_list_node	*tmp;

	ms_parse_skip_space_if_any(head);
	tmp = *head;
	result = 0;
	while (tmp->value.type == MS_PARSE_TOKEN_TYPE_WORD
		|| tmp->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| tmp->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

static void	fill_free(t_ms_part_simple_node *array)
{
	t_ms_part_simple_node	*current;

	current = &array[-1];
	while (++current->content)
		free(current->content);
}

static t_err	fill(
	t_ms_parse_token_list_node **head,
	t_ms_part_simple_node *array
)
{
	size_t	index;

	index = 0;
	while ((*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD
		|| (*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| (*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
	{
		if (ft_cstring_duplicate((*head)->value.data, &array[index].content))
		{
			fill_free(array);
			return (true);
		}
		if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD)
			array[index].type = MS_PART_SIMPLE_NORMAL;
		else if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
			array[index].type = MS_PART_SIMPLE_QUOTED;
		else
			array[index].type = MS_PART_SIMPLE_DOUBLE_QUOTED;
		index++;
		*head = (*head)->next;
	}
	return (false);
}

t_err	ms_parse_parse_ms_simple_part(
	t_ms_parse_token_list_node **head,
	t_ms_part_simple *out
)
{
	const size_t		length = count(head);
	t_ms_part_simple	result;

	result.length = length;
	result.array = malloc(sizeof(t_ms_part_simple_node) * length);
	if (!length || !result.array || fill(head, result.array))
	{
		free(result.array);
		if (!length)
		{
			*out = (t_ms_part_simple){NULL, 0};
			return (false);
		}
		return (true);
	}
	*out = result;
	return (false);
}
