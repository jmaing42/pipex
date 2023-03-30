/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/30 15:57:53 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXPAND_H
# define MS_EXPAND_H

# include "ft_stringbuilder.h"
# include "ms.h"

# include <stdbool.h>

# define STRING_BUILDER_SIZE 32
# define ENVS_SIZE 32

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
	t_ms_expand_string_list						list;
}	t_ms_expand_string_list_list_node;

typedef struct s_ms_expand_string_list_list
{
	t_ms_expand_string_list_list_node	*head;
	t_ms_expand_string_list_list_node	*tail;
}	t_ms_expand_string_list_list;

typedef struct s_ms_expand_string_list_list_builder
{
	t_ms_expand_string_list_list	list;
	t_stringbuilder					*builder;
}	t_ms_expand_string_list_list_builder;

typedef struct s_ms_expand_env_list_node
{
	struct s_ms_expand_env_list_node	*next;
	const char							*key;
	const char							*value;
}	t_ms_expand_env_list_node;

typedef struct s_ms_expand_env_list
{
	t_ms_expand_env_list_node	*head;
	t_ms_expand_env_list_node	*tail;
}	t_ms_expand_env_list;
//setup
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
t_err		ms_expand(
				t_ms_word_list *list,
				char ***out_argv);
t_err		ms_expand_string_list_node_add(
				t_ms_expand_string_list *self);
t_err		ms_expand_string_list_list_node_add(
				t_ms_expand_string_list_list *self);
t_err		ms_expand_string_list_list_builder_fill_node(
				t_stringbuilder **builder,
				t_ms_expand_string_list *list);
void		ms_expand_string_list_free(t_ms_expand_string_list *list);
void		ms_expand_string_list_list_free(t_ms_expand_string_list_list *list);
void		ms_expand_string_list_list_builder_free(
				t_ms_expand_string_list_list_builder *self);
t_err		ms_expand_string_list_list_builder_finalize(
				t_ms_expand_string_list_list_builder *self,
				t_ms_expand_string_list_list *out);
t_err		ms_expand_init(void);
t_err		ms_expand_internal(
				t_ms_word_list *list,
				t_ms_expand_string_list *out);
void		*ms_expand_env_list_get(void);
t_err		ms_expand_putenv(const char *key, const char *value);
const char	*ms_expand_getenv(const char *key);
char		*ms_expand_strnstr(
				const char *haystack,
				const char *needle,
				size_t len);
t_err		ms_expand_asterisk(
				t_ms_expand_string_list_list *string_list_list,
				t_ms_expand_string_list *out_string_list);
//

#endif
