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

#include <stdlib.h>

#include "ms.h"
#include "ms_expand.h"
#include "ms_repl.h"

extern char	**environ;

int	main(void)
{
	if (ms_repl_set_termianl())
		ms_repl_die();
	if (ms_expand_env_init(environ))
		ms_repl_die();
	if (ms_tmpname_init())
		ms_repl_die();
	ms_repl_main();
	return (EXIT_SUCCESS);
}
