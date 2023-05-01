/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_repl_set_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/29 16:51:16 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_repl.h"

#include <stdio.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <sys/termios.h>
#include <unistd.h>

#include "ft_io.h"
#include "ms_execute.h"
#include "readline/readline.h"
#include "wrap.h"

static void	sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	ms_execute_globals()->exit_status = EXIT_BY_SIGINT;
	wrap_write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == FAIL)
		wrap_exit(EXIT_FAILURE);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_repl_set_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}