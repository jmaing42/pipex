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

#ifndef MS_H
# define MS_H

# include <stdbool.h>
# include <stddef.h>

# include "ft_types.h"

typedef enum e_ms_word_part_string_type
{
	MS_WORD_PART_STRING_NO_EXPANSION,
	MS_WORD_PART_STRING_EXPANSION,
}	t_ms_word_part_string_type;

typedef struct s_ms_word_part_string_list_node
{
	struct s_ms_word_part_string_list_node	*next;
	t_ms_word_part_string_type				type;
	char									*value;
}	t_ms_word_part_string_list_node;

typedef struct s_ms_word_part_string_list
{
	t_ms_word_part_string_list_node	*head;
	t_ms_word_part_string_list_node	*tail;
}	t_ms_word_part_string_list;

typedef t_ms_word_part_string_list	*t_ms_word_part_unquoted;

typedef char						*t_ms_word_part_single_quoted;

typedef t_ms_word_part_string_list	*t_ms_word_part_double_quoted;

typedef enum e_ms_word_part_type
{
	MS_WORD_PART_UNQUOTED,
	MS_WORD_PART_SINGLE_QUOTED,
	MS_WORD_PART_DOUBLE_QUOTED,
}	t_ms_word_part_type;

typedef union u_ms_word_part_value
{
	t_ms_word_part_unquoted			*unquoted;
	t_ms_word_part_single_quoted	*single_quoted;
	t_ms_word_part_double_quoted	*double_quoted;
}	t_ms_word_part_value;

typedef struct s_ms_word_part_list_node
{
	struct s_ms_word_part_list_node	*next;
	t_ms_word_part_type				type;
	t_ms_word_part_value			value;
}	t_ms_word_part_list_node;

typedef struct s_ms_word_part_list
{
	t_ms_word_part_list_node	*head;
	t_ms_word_part_list_node	*tail;
}	t_ms_word_part_list;

typedef struct s_ms_word
{
	t_ms_word_part_list	part_list;
}	t_ms_word;

typedef struct s_ms_word_list_node
{
	struct s_ms_word_list_node	*next;
	t_ms_word					word;
}	t_ms_word_list_node;

typedef struct s_ms_word_list
{
	t_ms_word_list_node	*head;
	t_ms_word_list_node	*tail;
}	t_ms_word_list;

typedef struct s_ms_input_redirection_list_node
{
	struct s_ms_input_redirection_list	*next;
	bool								is_heredoc;
	t_ms_word							to;
}	t_ms_input_redirection_list_node;

typedef struct s_ms_input_redirection_list
{
	t_ms_input_redirection_list_node	*head;
	t_ms_input_redirection_list_node	*tail;
}	t_ms_input_redirection_list;

typedef struct s_ms_output_redirection_list_node
{
	struct s_ms_output_redirection_list	*next;
	bool								is_append;
	t_ms_word							to;
}	t_ms_output_redirection_list_node;

typedef struct s_ms_output_redirection_list
{
	t_ms_output_redirection_list_node	*head;
	t_ms_output_redirection_list_node	*tail;
}	t_ms_output_redirection_list;

typedef struct s_ms_redirections
{
	t_ms_input_redirection_list		stdin;
	t_ms_output_redirection_list	stdout;
}	t_ms_redirections;

typedef struct s_ms_command_simple
{
	t_ms_word_list		*word_list;
	t_ms_redirections	redirections;
}	t_ms_command_simple;

typedef struct s_ms_command_compound
{
	struct s_ms_and_or_list	*and_or_list;
	t_ms_redirections		redirections;
}	t_ms_command_compound;

typedef enum e_ms_command_type
{
	MS_COMMAND_TYPE_SIMPLE,
	MS_COMMAND_TYPE_COMPOUND,
}	t_ms_command_type;

typedef union u_ms_command_value
{
	t_ms_command_simple		*simple;
	t_ms_command_compound	*compound;
}	t_ms_command_value;

typedef struct s_ms_command
{
	t_ms_command_type	type;
	t_ms_command_value	value;
}	t_ms_command;

typedef struct s_ms_pipe_list_node
{
	struct s_ms_pipe_list_node	*next;
	t_ms_command				command;
}	t_ms_pipe_list_node;

typedef struct s_ms_pipe_list
{
	t_ms_pipe_list_node	*head;
	t_ms_pipe_list_node	*tail;
}	t_ms_pipe_list;

typedef struct s_ms_and_or_list_node
{
	struct s_ms_and_or_list_node	*next;
	bool							is_and;
	t_ms_pipe_list					pipe_list;
}	t_ms_and_or_list_node;

typedef struct s_ms_and_or_list
{
	t_ms_and_or_list_node	*head;
	t_ms_and_or_list_node	*tail;
}	t_ms_and_or_list;

typedef struct s_ms_program
{
	t_ms_and_or_list	and_or_list;
}	t_ms_program;

t_err	ms_tmpname(char **out);

#endif
