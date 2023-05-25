/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_signal_message.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:26:06 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/07 21:13:31 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <sys/signal.h>
#include <unistd.h>

#include "ft_io.h"

t_err	ms_execute_signal_message(int signo)
{
	ms_execute_globals()->exit_status = 128 + signo;
	if (signo == SIGINT)
	{
		if (ft_puts(STDOUT_FILENO, "\n"))
			return (true);
	}
	else if (signo == SIGQUIT)
	{
		if (ft_puts(STDOUT_FILENO, "Quit: 3\n"))
			return (true);
	}
	return (false);
}
