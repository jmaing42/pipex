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

#ifndef MS_EXPAND_H
# define MS_EXPAND_H

#include "ft_stringbuilder.h"
# include "ms.h"

# include <stdbool.h>

typedef struct s_ms_expand_tmp_string
{
	char				*str;
	t_ms_word_part_type	type;
}	t_ms_expand_tmp_string;

typedef struct s_ms_expand_string_list_node
{
	struct s_ms_expand_string_list_node	*next;
	char								*str;
}	t_ms_expand_string_list_node;

typedef struct s_ms_expand_string_list
{
	t_ms_expand_string_list_node	*head;
	t_ms_expand_string_list_node	*tail;
}	t_ms_expand_string_list;

typedef struct s_ms_expand_string_list_list_node
{
	struct s_ms_expand_string_list_list_node	*next;
	t_ms_expand_string_list						*list;
}	t_ms_expand_string_list_list_node;

typedef struct s_ms_expand_string_list_list
{
	t_ms_expand_string_list_list_node	*head;
	t_ms_expand_string_list_list_node	*tail;
}	t_ms_expand_string_list_list;

typedef struct s_ms_expand_string_list_list_builder
{
	t_ms_expand_string_list_list	list;
	bool							append_to_tail;
	t_stringbuilder					*builder;
}	t_ms_expand_string_list_list_builder;

void		ms_expand_string_list_free(t_ms_expand_string_list list);
void		ms_expand_string_list_list_free(t_ms_expand_string_list_list list);
t_err		ms_expand_tmp_string(
				t_ms_word_part_list_node *part,
				t_ms_expand_tmp_string *out);
char		*ms_expand_word_part_string_list(
				t_ms_word_part_string_list *input);
void		ms_expand_string_list_list_builder_init(
				t_ms_expand_string_list_list_builder *out);
t_err		ms_expand_string_list_list_builder_feed_word_list(
				t_ms_expand_string_list_list_builder *self,
				t_ms_word_list *list);
t_err		ms_expand_string_list_list_builder_feed_word(
				t_ms_expand_string_list_list_builder *self,
				t_ms_word *word);
t_err		ms_expand_string_list_list_builder_feed_word_part_list(
				t_ms_expand_string_list_list_builder *self,
				t_ms_word_part_list *list);
t_err		ms_expand_string_list_list_builder_feed_word_part_list_node(
				t_ms_expand_string_list_list_builder *self,
				t_ms_word_part_list_node *node);
t_err		ms_expand_string_list_list_builder_feed_string(
				t_ms_expand_string_list_list_builder *self,
				const char *str,
				t_ms_word_part_type type);
t_err		ms_expand_string_list_list_builder_feed_char(
				t_ms_expand_string_list_list_builder *self,
				const char ch,
				t_ms_word_part_type type);
t_err		ms_expand_string_list_list_builder_set_skip(
				t_ms_expand_string_list_list_builder *self);
t_err		ms_expand_string_list_list_builder_finalize(
				t_ms_expand_string_list_list_builder *self,
				t_ms_expand_string_list_list *out);
void		ms_expand_string_list_list_builder_free(
				t_ms_expand_string_list_list_builder *self);
t_err		ms_expand_asterisk(
				t_ms_expand_string_list_list string_list_list,
				t_ms_expand_string_list *out_string_list);
t_err		ms_expand_internal(
				t_ms_word_list *list,
				t_ms_expand_string_list *out);
const char	*ms_expand_getenv(const char *key);
t_err		ms_expand_putenv(const char *key, const char *value);
t_err		ms_expand_init(void);

t_err		ms_expand(
				t_ms_word_list *list,
				char ***out_argv);

#endif
