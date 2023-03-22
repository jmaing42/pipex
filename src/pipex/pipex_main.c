/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/22 19:54:01 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_cstring.h"
#include "ft_stringbuilder.h"
#include "ft_io.h"
#include "ms.h"
#include "ms_execute.h"

typedef struct s_to_string
{
	char		**arr;
	size_t		length;
	bool		is_heredoc;
	const char	*in_file;
	const char	*out_file;
	char		**out;
}	t_to_string;

static bool	is_heredoc(int argc, char **argv)
{
	return (argc >= 2 && ft_cstring_equals(argv[1], "here_doc"));
}

t_err	to_string(t_to_string v)
{
	t_stringbuilder *const	result = new_stringbuilder(1024);
	size_t					i;
	t_err					error;

	if (!result)
		return (true);
	error = false;
	i = !!v.is_heredoc - 1;
	error |= ((v.is_heredoc && stringbuilder_append_string(result, "<<"))
			|| (!v.is_heredoc && stringbuilder_append_string(result, "<"))
			|| stringbuilder_append_string(result, v.in_file));
	while (++i < v.length && !error)
		error |= ((i != 0 && stringbuilder_append_string(result, " |"))
				|| stringbuilder_append_string(result, " (")
				|| stringbuilder_append_string(result, v.arr[i])
				|| stringbuilder_append_string(result, ")"));
	error |= stringbuilder_append_string(result, ">");
	error |= stringbuilder_append_string(result, v.out_file);
	if (error)
		stringbuilder_free(result);
	if (error)
		return (true);
	*v.out = stringbuilder_to_string(result, 0);
	stringbuilder_free(result);
	return (*v.out == NULL);
}

int	pipex_main(int argc, char **argv)
{
	const bool		hd = is_heredoc(argc, argv);
	char			*source;
	t_ms_program	*program;
	int				result;

	if (argc < 4)
		return (EXIT_FAILURE);
	if (to_string((t_to_string){argv + 2 + !!hd, argc - (2 + !!hd) - 1,
			hd, argv[1], argv[argc - 1], &source}))
		return (EXIT_FAILURE);
	if (ms_parse(source, &program))
	{
		wrap_free(source);
		return (EXIT_FAILURE);
	}
	if (!program)
	{
		ft_write(STDERR_FILENO, "Syntax error!\n", 14);
		return (EXIT_SUCCESS);
	}
	ms_execute(program, &result);
	wrap_free(source);
	ms_free(program);
	return (result);
}
