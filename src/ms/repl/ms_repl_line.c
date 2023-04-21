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

#include "ft_types_char.h"
#include "ms_execute.h"
#include "ms_repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "ms.h"
#include "ft_io.h"
#include "wrap.h"

static bool	is_empty_str(char *line)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (!ft_types_char_space(line[index]))
			return (false);
		++index;
	}
	return (true);
}

void	ms_repl_line(void)
{
	t_ms_program			*program;
	t_ms_repl_string_list	*tmp_files;
	char *const				line = readline("minishell> ");

	if (line == NULL)
		ms_execute_exit(EXIT_FAILURE, "minishell line malloc");
	if (is_empty_str(line))
	{
		free(line);
		return ;
	}
	add_history(line);
	ms_repl_die_if(ms_parse(line, &program));
	if (!program)
	{
		ft_puts(STDERR_FILENO, "syntax error\n");
		return ;
	}
	ms_repl_die_if(ms_repl_replace_heredoc(program, &tmp_files));
	ms_repl_die_if(ms_execute(program));
	wrap_free(line);
}
