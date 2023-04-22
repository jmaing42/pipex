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
#include "ms_execute.h"

#include <stdlib.h>
#include <signal.h>
#include <sys/_types/_pid_t.h>

#include "wrap.h"

void	parent_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	if (ft_puts(STDOUT_FILENO, "\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell handler");
}

static void	child_signal(void)
{
	signal(SIGINT, SIG_DFL);
}

static void	parent_signal(void)
{
	signal(SIGINT, parent_sigint_handler);
}

void	ms_execute_set_signals(pid_t pid)
{
	if (pid == CHILD_PID)
		child_signal();
	else
		parent_signal();
}
