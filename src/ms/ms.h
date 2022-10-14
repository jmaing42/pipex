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

typedef struct s_ms_file_list
{
	char	**array;
	size_t	length;
}	t_ms_file_list;

typedef struct s_ms_tmp_list
{
	char	**array;
	size_t	length;
}	t_ms_tmp_list;

typedef enum e_ms_part_type
{
	MS_PART_TYPE_SIMPLE,
	MS_PART_TYPE_COMPOUND,
}	t_ms_part_type;

typedef struct s_ms_part_simple
{
	char	**arguments;
	char	**variables;
}	t_ms_part_simple;

typedef struct s_ms_part_compound
{
	struct s_ms_compound	*array;
	size_t					length;
}	t_ms_part_compound;

typedef union u_ms_part
{
	t_ms_part_simple	simple;
	t_ms_part_compound	compound;
}	t_ms_part;

typedef struct s_ms
{
	t_ms_file_list	stdin;
	t_ms_file_list	stdout;
	t_ms_file_list	stderr;
	t_ms_tmp_list	tmp;
	t_ms_part_type	type;
	t_ms_part		part;
}	t_ms;

typedef enum s_ms_compound_type
{
	MS_COMPOUND_TYPE_AND,
	MS_COMPOUND_TYPE_OR,
}	t_ms_compound_type;

typedef struct s_ms_compound
{
	t_ms				node;
	t_ms_compound_type	type;
}	t_ms_compound;

t_err	ms_validate(const char *str, bool *out);
t_err	ms_parse(const char *str, t_ms **out);
t_err	ms_run(t_ms *node, char **variables);
void	ms_free(t_ms *node);

t_err	ms_tmpname(char **out);

#endif
