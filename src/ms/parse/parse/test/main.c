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

#include <stdio.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ms_parse.h"
#include "ft/leak_test.h"

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
	const char *const	contents = context;
	t_ms_program		*list;

	leak_test_start();
	if (!ms_parse(contents, &list))
		ms_free(list);
	return (false);
}

int	main(int argc, char **argv)
{
	char			*contents;
	t_ms_program	*program;
	int				errno;
	t_err			error;

	if (argc < 2 || read_file_contents(argv[1], &contents))
		return (EXIT_FAILURE);
	errno = leak_test(test_leak, contents, NULL);
	if (errno && printf("leak_test: %s\n", leak_test_error(errno)) < 0)
	{
		free(contents);
		return (EXIT_FAILURE);
	}
	error = !!errno;
	if (ms_parse(contents, &program))
	{
		free(contents);
		return (EXIT_FAILURE);
	}
	error |= print_program(program);
	ms_free(program);
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
