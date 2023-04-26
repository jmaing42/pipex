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
#include "ft_types_char.h"
#include "ms_builtin.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>

#include "ms_execute.h"
#include "wrap.h"

static t_err	print(char *message, int fd)
{
	if (ft_puts(fd, message))
	{
		perror("minishell exit");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return (true);
	}
	return (false);
}

static long long	my_atoi(const char *str)
{
	long long	num;
	int			minus;

	num = 0;
	minus = 1;
	while (*str && ft_types_char_space(*str))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = num * 10 + (*str - '0');
		if (minus * num > INT_MAX || minus * num < INT_MIN)
			return ((long long)INT_MAX + 1);
		str++;
	}
	if (*str && (*str < '0' || *str > '9'))
		return ((long long)INT_MAX + 1);
	num *= minus;
	return (num);
}

void	ms_builtin_exit(char **args, int fd)
{
	long long	exit_code;

	if (print("exit\n", fd))
		return ;
	exit_code = ms_execute_globals()->exit_status;
	if (args[1])
	{
		exit_code = my_atoi(args[1]);
		if (exit_code > INT_MAX)
		{
			if (print("minishell exit: numeric argument required\n",
					STDERR_FILENO))
				return ;
			wrap_exit(-1);
		}
	}
	wrap_exit(exit_code);
}
