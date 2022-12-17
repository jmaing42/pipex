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

#ifndef MS_PARSE_H
# define MS_PARSE_H

# include "ms.h"

# include "ft_stringbuilder.h"

typedef enum e_ms_parse_token_type
{
	MS_PARSE_TOKEN_TYPE_EOF,
	MS_PARSE_TOKEN_TYPE_AND,
	MS_PARSE_TOKEN_TYPE_OR,
	MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON,
	MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON,
	MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS,
	MS_PARSE_TOKEN_TYPE_RIGHT_PARENTHESIS,
	MS_PARSE_TOKEN_TYPE_SPACE,
	MS_PARSE_TOKEN_TYPE_WORD,
	MS_PARSE_TOKEN_TYPE_WORD_QUOTED,
	MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED,
}	t_ms_parse_token_type;

typedef struct s_ms_parse_token
{
	t_ms_parse_token_type	type;
	char					*data;
}	t_ms_parse_token;

typedef struct s_ms_parse_token_list_node
{
	struct s_ms_parse_token_list_node	*next;
	t_ms_parse_token					value;
}	t_ms_parse_token_list_node;

typedef struct s_ms_parse_token_list
{
	t_ms_parse_token_list_node	*head;
	t_ms_parse_token_list_node	*tail;
}	t_ms_parse_token_list;

t_err	ms_parse_tokenize(const char *str, t_ms_parse_token_list *out);
void	ms_parse_tokenize_free(t_ms_parse_token_list *list);

# define MS_PARSE_TOKENIZE_STATE_ERROR -1
# define MS_PARSE_TOKENIZE_STATE_DEFAULT 0
# define MS_PARSE_TOKENIZE_STATE_SPACE 1
# define MS_PARSE_TOKENIZE_STATE_WORD 2
# define MS_PARSE_TOKENIZE_STATE_QUOTE 3
# define MS_PARSE_TOKENIZE_STATE_DOUBLE_QUOTE 4

typedef struct s_ms_parse_tokenize_state
{
	int				state;
	t_stringbuilder	*data;
}	t_ms_parse_tokenize_state;

typedef t_err	(*t_ms_parse_tokenize_function)(
					char c,
					t_ms_parse_token_list *list,
					t_stringbuilder *data,
					t_ms_parse_tokenize_state *out_next_state);

t_err	ms_parse_tokenize_state_default(
			char c,
			t_ms_parse_token_list *list,
			t_stringbuilder *data,
			t_ms_parse_tokenize_state *out_next_state);
t_err	ms_parse_tokenize_state_space(
			char c,
			t_ms_parse_token_list *list,
			t_stringbuilder *data,
			t_ms_parse_tokenize_state *out_next_state);
t_err	ms_parse_tokenize_state_word(
			char c,
			t_ms_parse_token_list *list,
			t_stringbuilder *data,
			t_ms_parse_tokenize_state *out_next_state);
t_err	ms_parse_tokenize_state_quote(
			char c,
			t_ms_parse_token_list *list,
			t_stringbuilder *data,
			t_ms_parse_tokenize_state *out_next_state);
t_err	ms_parse_tokenize_state_double_quote(
			char c,
			t_ms_parse_token_list *list,
			t_stringbuilder *data,
			t_ms_parse_tokenize_state *out_next_state);

t_err	ms_parse_tokenize_add_simple_token(
			t_ms_parse_token_list *list,
			t_ms_parse_token_type type);
t_err	ms_parse_tokenize_add_string_token(
			t_ms_parse_token_list *list,
			t_ms_parse_token_type type,
			t_stringbuilder *data);

t_err	ms_parse_parse_program(
			t_ms_parse_token_list_node **mut_head,
			t_ms_program **out);
t_err	ms_parse_parse_and_or_list(
			t_ms_parse_token_list_node **mut_head,
			t_ms_and_or_list *out);
t_err	ms_parse_parse_pipe_list(
			t_ms_parse_token_list_node **mut_head,
			t_ms_pipe_list *out);
t_err	ms_parse_parse_command(
			t_ms_parse_token_list_node **mut_head,
			t_ms_command *out);
bool	ms_parse_parse_command_is_word(
			t_ms_parse_token_list_node *head);
t_err	ms_parse_parse_command_add_redirection(
			t_ms_parse_token_list_node **mut_head,
			t_ms_redirections *mut_redirections);
bool	ms_parse_parse_command_is_redirection(
			t_ms_parse_token_list_node **mut_head);
t_err	ms_parse_parse_command_compound(
			t_ms_parse_token_list_node **mut_head,
			t_ms_redirections redirections,
			t_ms_command *out);
t_err	ms_parse_parse_command_simple(
			t_ms_parse_token_list_node **mut_head,
			t_ms_redirections redirections,
			t_ms_command *out);
t_err	ms_parse_parse_word(
			t_ms_parse_token_list_node **mut_head,
			t_ms_word **out);
t_err	ms_parse_parse_word_part_unquoted(
			const char *data,
			t_ms_word_part_string_list **out);
t_err	ms_parse_parse_word_part_single_quoted(
			const char *data,
			char **out);
t_err	ms_parse_parse_word_part_double_quoted(
			const char *data,
			t_ms_word_part_string_list **out);
t_err	ms_parse_parse_word_part_fill(
			const char *data,
			t_ms_word_part_string_list *mut_list);

void	ms_parse_free_program(
			t_ms_program *program);
void	ms_parse_free_and_or_list(
			t_ms_and_or_list *and_or_list);
void	ms_parse_free_pipe_list(
			t_ms_pipe_list *pipe_list);
void	ms_parse_free_redirections(
			t_ms_redirections *redirections);
void	ms_parse_free_command(
			t_ms_command *command);
void	ms_parse_free_word(
			t_ms_word *word);
void	ms_parse_free_word_part_list(
			t_ms_word_part_list *list);
void	ms_parse_free_word_part(
			t_ms_word_part_type type,
			t_ms_word_part_value value);
void	ms_parse_free_word_part_string_list(
			t_ms_word_part_string_list *string_list);

void	ms_parse_parse_util_skip_space_if_any(
			t_ms_parse_token_list_node **mut_head);

#endif
