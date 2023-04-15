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

#include "ft_io.h"
#include "ms_repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>

#include <readline/readline.h>

#include "ms.h"

void	ms_repl_line(void)
{
	t_ms_program			*program;
	t_ms_repl_string_list	*tmp_files;
	char *const				line = readline("minishell> ");

	ms_repl_die_if(ms_parse(line, &program));
	if (!program)
	{
		ft_puts(STDERR_FILENO, "syntax error\n");
		return ;
	}
	ms_repl_die_if(ms_repl_replace_heredoc(program, &tmp_files));
	ms_repl_die_if(ms_execute(program));
}
