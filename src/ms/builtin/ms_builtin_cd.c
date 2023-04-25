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

#include "ft_cstring.h"
#include "ms_builtin.h"

#include <stdio.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <stdlib.h>

#include "ms_execute.h"
#include "wrap.h"

void	ms_builtin_cd(const char *const path)
{
	if (path == NULL || ft_cstring_equals(path, ""))
		return ;
	if (chdir(path) == FAIL)
	{
		perror("minishell cd");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return ;
	}
	ms_execute_globals()->exit_status = EXIT_SUCCESS;
}
