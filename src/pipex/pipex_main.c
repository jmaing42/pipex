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

#include "pipex.h"

#include <stdlib.h>
#include <sys/_types/_size_t.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_cstring.h"
#include "ft_stringbuilder.h"
#include "ft_io.h"
#include "ms.h"
#include "ms_expand.h"
// #include "ms_execute.h"

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
	t_stringbuilder *const	result = ft_stringbuilder_new(1024);
	size_t					i;
	t_err					error;

	if (!result)
		return (true);
	error = false;
	i = !!v.is_heredoc - 1;
	error |= ((v.is_heredoc && ft_stringbuilder_append_string(result, "<<"))
			|| (!v.is_heredoc && ft_stringbuilder_append_string(result, "<"))
			|| ft_stringbuilder_append_string(result, v.in_file));
	while (++i < v.length && !error)
		error |= ((i != 0 && ft_stringbuilder_append_string(result, " |"))
				|| ft_stringbuilder_append_string(result, " (")
				|| ft_stringbuilder_append_string(result, v.arr[i])
				|| ft_stringbuilder_append_string(result, ")"));
	error |= ft_stringbuilder_append_string(result, ">");
	error |= ft_stringbuilder_append_string(result, v.out_file);
	if (error)
		ft_stringbuilder_free(result);
	if (error)
		return (true);
	*v.out = ft_stringbuilder_to_string(result, 0);
	ft_stringbuilder_free(result);
	return (*v.out == NULL);
}

int	pipex_main(int argc, char **argv, char **envp)
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
	if (ms_expand_env_init(envp))
		return (EXIT_FAILURE);
	result = ms_execute(program);
	wrap_free(source);
	ms_free(program);
	return (result);
}
