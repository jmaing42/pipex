/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/17 17:55:08 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ms_expand.h"
#include "ms_repl.h"

extern char	**environ;

int	main(void)
{
	ms_expand_env_init(environ);
	ms_repl_install_signal_handlers();
	ms_repl_main();
	return (EXIT_SUCCESS);
}
