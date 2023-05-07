/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_set_signals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/06 22:41:25 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/_types/_pid_t.h>
#include <sys/signal.h>

#include "ft_io.h"
#include "wrap.h"

static void	sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	if (ft_puts(STDOUT_FILENO, "\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell sigint");
}

static void	sigquit_handler(int signo)
{
	if (signo != SIGQUIT)
		return ;
	if (ft_puts(STDOUT_FILENO, "Quit: 3\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell sigquit");
}

void	ms_execute_set_signals(pid_t pid)
{
	if (pid == CHILD_PID)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return ;
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
