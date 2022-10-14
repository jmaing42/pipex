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

typedef struct s_ms_fd_list
{
	int		*array;
	size_t	length;
}	t_ms_fd_list;

typedef struct s_ms_tmp_list
{
	char	**array;
	size_t	length;
}	t_ms_tmp_list;

typedef enum e_ms_node_part_type
{
	MS_NODE_PART_TYPE_SIMPLE,
	MS_NODE_PART_TYPE_COMPOUND,
}	t_ms_node_part_type;

typedef struct s_ms_node_part_simple
{
	char	**arguments;
	char	**variables;
}	t_ms_node_part_simple;

typedef struct s_ms_node_part_compound
{
	struct s_ms_node_compound	*array;
	size_t						length;
}	t_ms_node_part_compound;

typedef union u_ms_node_part
{
	t_ms_node_part_simple	simple;
	t_ms_node_part_compound	compound;
}	t_ms_node_part;

typedef struct s_ms_node
{
	int					stdin_pipe;
	int					stdout_pipe;
	int					stderr_pipe;
	t_ms_fd_list		stdin_fds;
	t_ms_fd_list		stdout_fds;
	t_ms_fd_list		stderr_fds;
	t_ms_tmp_list		tmp_files;
	t_ms_node_part_type	part_type;
	t_ms_node_part		part;
}	t_ms_node;

typedef enum s_ms_node_compound_type
{
	MS_NODE_COMPOUND_TYPE_AND,
	MS_NODE_COMPOUND_TYPE_OR,
}	t_ms_node_compound_type;

typedef struct s_ms_node_compound
{
	t_ms_node				node;
	t_ms_node_compound_type	type;
}	t_ms_node_compound;

typedef struct s_ms_node_validate_result
{
	bool	complete;
	bool	unrecoverable_error;
}	t_ms_node_validate_result;

typedef struct s_ms_node_parse_result
{
	t_ms_node	*result;
}	t_ms_node_parse_result;

t_err	ms_validate(const char *str, t_ms_node_validate_result *out);
t_err	ms_parse(const char *str, t_ms_node_parse_result *out);
t_err	ms_run(t_ms_node *node, char ***variables);
void	ms_free(t_ms_node *node);

#endif
