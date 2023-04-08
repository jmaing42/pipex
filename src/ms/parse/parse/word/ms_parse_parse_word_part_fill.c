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

#include "ms_parse.h"

#include "ft_cstring.h"
#include "ft_types_char.h"
#include "wrap.h"

static size_t	length_of_expansion(const char *data)
{
	size_t	length;

	if (*data != '$' || (!ft_types_char_alpha(data[1]) && data[1] != '_'))
		return (0);
	length = 2;
	while (ft_types_char_alnum(data[length]) || data[length] == '_')
		length++;
	return (length);
}

static t_err	add_expansion(
	const char *data,
	t_ms_word_part_string_list *mut_list,
	size_t *out_added_length
)
{
	const size_t							length
		= length_of_expansion(data);
	t_ms_word_part_string_list_node *const	node
		= wrap_malloc(sizeof(t_ms_word_part_string_list_node));

	if (!node)
		return (true);
	if (ft_cstring_duplicate_length(data + 1, length - 1, &node->value))
	{
		wrap_free(node);
		return (true);
	}
	node->next = NULL;
	node->type = ms_word_part_string_expansion;
	if (mut_list->head)
		mut_list->tail->next = node;
	else
		mut_list->head = node;
	mut_list->tail = node;
	*out_added_length = length;
	return (false);
}

static size_t	length_of_no_expansion(const char *data)
{
	size_t	length;

	length = ft_cstring_find_index(data, '$');
	while (data[length] == '$'
		&& !(ft_types_char_alpha(data[length + 1]) || data[length + 1] == '_'))
		length = length + 1 + ft_cstring_find_index(data + length + 1, '$');
	return (length);
}

static t_err	add_no_expansion(
	const char *data,
	t_ms_word_part_string_list *mut_list,
	size_t *out_added_length
)
{
	const size_t							length
		= length_of_no_expansion(data);
	t_ms_word_part_string_list_node *const	node
		= wrap_malloc(sizeof(t_ms_word_part_string_list_node));

	if (!node)
		return (true);
	if (ft_cstring_duplicate_length(data, length, &node->value))
	{
		wrap_free(node);
		return (true);
	}
	node->next = NULL;
	node->type = ms_word_part_string_no_expansion;
	if (mut_list->head)
		mut_list->tail->next = node;
	else
		mut_list->head = node;
	mut_list->tail = node;
	*out_added_length = length;
	return (false);
}

t_err	ms_parse_parse_word_part_fill(
	const char *data,
	t_ms_word_part_string_list *mut_list
)
{
	const char	*current;
	size_t		added_length;

	current = data;
	while (*current)
	{
		if (length_of_expansion(current))
		{
			if (add_expansion(current, mut_list, &added_length))
				return (true);
		}
		else
		{
			if (add_no_expansion(current, mut_list, &added_length))
				return (true);
		}
		current = current + added_length;
	}
	return (false);
}
