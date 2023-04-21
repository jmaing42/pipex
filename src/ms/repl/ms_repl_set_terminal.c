/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_repl_set_terminal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:34:12 by seonlim           #+#    #+#             */
/*   Updated: 2023/04/21 18:35:43 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_repl.h"

#include <termios.h>
#include <stdlib.h>

#include "wrap.h"

void	ms_repl_set_termianl(void)
{
	struct termios	new_term;

	if (tcgetattr(STDIN_FILENO, &new_term))
		wrap_exit(EXIT_FAILURE);
	new_term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &new_term);
}
