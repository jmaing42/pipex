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

#include "ms_execute.h"

#include <stdlib.h>
#include <signal.h>
#include <sys/_types/_pid_t.h>

#include "wrap.h"

static void	child_signal(void)
{
	signal(SIGINT, SIG_DFL);
}

static void	parent_signal(void)
{
	signal(SIGINT, SIG_IGN);
}

void	ms_execute_set_signals(pid_t pid)
{
	if (pid == CHILD_PID)
		child_signal();
	else
		parent_signal();
}
