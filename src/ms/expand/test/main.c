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

#include "test.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ms.h"
#include "ft_types.h"
#include "ms_parse.h"
#include "ms_expand.h"
#include "ft/leak_test.h"

extern char	**environ;

static t_err	read_file_contents(const char *filename, char **out)
{
	FILE *const		fp = fopen(filename, "rb");
	unsigned long	length;
	bool			error;

	length = 0;
	error = !fp;
	*out = NULL;
	if (!error && fseek(fp, 0, SEEK_END))
		error = true;
	if (!error)
		length = ftell(fp);
	if (!error && fseek(fp, 0, SEEK_SET))
		error = true;
	if (!error)
		*out = malloc(length + 1);
	if (!*out)
		error = true;
	if (!error && fread(*out, 1, length, fp) != length)
		error = true;
	if (fp)
		fclose(fp);
	if (error)
		free(*out);
	(*out)[length] = '\0';
	return (error);
}

static bool	test_leak(const void *context)
{
	const t_ms_program *const	program = context;

	leak_test_start();
	if (test_program(program))
		return (false);
	return (false);
}

int	main(int argc, char **argv)
{
	char			*contents;
	int				errno;
	t_err			error;
	t_ms_program	*program;

	if (argc < 2 || ms_expand_env_init(environ)
		|| read_file_contents(argv[1], &contents))
		return (EXIT_FAILURE);
	ms_parse(contents, &program);
	errno = leak_test(test_leak, program, NULL);
	if (errno && printf("leak_test: %s\n", leak_test_error(errno)) < 0)
	{
		free(contents);
		return (EXIT_FAILURE);
	}
	error = !!errno;
	if (!error && ms_parse(contents, &program))
		error = true;
	if (!error)
	{
		test_program(program);
		ms_free(program);
	}
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
