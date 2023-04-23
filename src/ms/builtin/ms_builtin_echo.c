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

#include "ms_builtin.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_cstring.h"
#include "ft_io.h"
#include "ms_execute.h"
#include "wrap.h"

static	void	print(char *message)
{
	if (ft_puts(STDOUT_FILENO, message))
	{
		perror("minishell echo");
		wrap_exit(EXIT_FAILURE);
	}
}

void	ms_builtin_echo(char **args)
{
	size_t	index;
	bool	no_enter;

	no_enter = false;
	index = 1;
	while (args[index])
	{
		if (index == 1 && ft_cstring_equals(args[index], "-n"))
			no_enter = true;
		else
		{
			print(args[index]);
			if (args[index + 1] != NULL)
				print(" ");
		}
		++index;
	}
	if (!no_enter)
		print("\n");
	ms_execute_globals()->exit_status = EXIT_SUCCESS;
}
