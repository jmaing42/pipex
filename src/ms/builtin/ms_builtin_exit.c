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

#include "ms_execute.h"
#include "wrap.h"

static void	print_message(int fd, char *message)
{
	if (ft_puts(fd, message))
	{
		perror("minishell exit");
		wrap_exit(EXIT_FAILURE);
	}
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

static long long	get_exit_code(char *str, bool *out_is_numeric)
{
	long long	exit_code;

	exit_code = my_atoi(str);
	if (exit_code > INT_MAX)
	{
		print_message(STDERR_FILENO,
			"minishell exit: numeric argument required\n");
		*out_is_numeric = false;
	}
	return (exit_code);
}

void	ms_builtin_exit(char **args)
{
	size_t		index;
	long long	exit_code;
	bool		is_numeric;

	print_message(STDOUT_FILENO, "exit\n");
	is_numeric = true;
	exit_code = ms_execute_globals()->exit_status;
	index = 1;
	while (args[index])
	{
		if (index > 1)
		{
			ms_execute_globals()->exit_status = EXIT_FAILURE;
			print_message(STDERR_FILENO, "minishell exit: too many arguments\n");
			return ;
		}
		else if (index == 1)
			exit_code = get_exit_code(args[index], &is_numeric);
		++index;
	}
	if (!is_numeric)
		wrap_exit(-1);
	wrap_exit(exit_code);
}
