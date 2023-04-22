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

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

#include "readline/readline.h"
#include "wrap.h"
#include "ms_execute.h"

static void	child_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	wrap_exit(EXIT_BY_SIGNAL);
}

static void	parent_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	if (ft_puts(STDOUT_FILENO, "\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell handler");
}

void	ms_repl_heredoc_signals(pid_t pid)
{
	if (pid == CHILD_PID)
	{
		signal(SIGINT, child_sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		return ;
	}
	signal(SIGINT, parent_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
