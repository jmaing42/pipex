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

#include "ms_repl.h"

#include <termios.h>
#include <stdlib.h>

#include "wrap.h"
#include "ms_execute.h"

t_err	ms_repl_set_termianl(void)
{
	struct termios	new_term;

	if (tcgetattr(STDIN_FILENO, &new_term) == FAIL)
		return (true);
	new_term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, 0, &new_term) == FAIL)
		return (true);
	return (false);
}
