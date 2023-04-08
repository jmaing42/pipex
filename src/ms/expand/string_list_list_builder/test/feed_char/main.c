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
#include <ctype.h>

#include "ft_types.h"
#include "ms.h"
#include "ms_expand.h"
#include "ft_cstring.h"
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

static t_ms_word_part_type	type(char c)
{
	if (c == 's')
		return (ms_word_part_single_quoted);
	if (c == 'd')
		return (ms_word_part_double_quoted);
	return (ms_word_part_unquoted);
}

static bool	test_leak(const void *context)
{
	const char *const						contents = context;
	t_ms_expand_string_list_list_builder	builder;
	size_t									i;

	leak_test_start();
	ms_expand_string_list_list_builder_init(&builder);
	if (ms_expand_string_list_list_builder_add_list_list_node(&builder.list))
		return (false);
	i = 0;
	while (contents[i] && contents[i + 1])
	{
		if (ms_expand_string_list_list_builder_feed_char(
				&builder, contents[i + 1], type(contents[i])))
			break ;
		i += 2;
		while (isspace(contents[i]))
			i++;
	}
	ms_expand_string_list_list_builder_free(&builder);
	return (false);
}

static t_err	test_func(char *contents)
{
	t_ms_expand_string_list_list_builder	builder;
	size_t									i;
	t_err									result;

	ms_expand_string_list_list_builder_init(&builder);
	i = 0;
	if (ms_expand_string_list_list_builder_add_list_list_node(&builder.list))
		return (false);
	while (contents[i] && contents[i + 1])
	{
		if (ms_expand_string_list_list_builder_feed_char(
				&builder, contents[i + 1], type(contents[i])))
		{
			ms_expand_string_list_list_builder_free(&builder);
			return (true);
		}
		i += 2;
		while (isspace(contents[i]))
			i++;
	}
	result = print_builder(&builder);
	ms_expand_string_list_list_builder_free(&builder);
	return (result);
}

int	main(int argc, char **argv)
{
	char									*contents;
	int										errno;
	t_err									error;

	if (argc < 2 || read_file_contents(argv[1], &contents))
		return (EXIT_FAILURE);
	errno = leak_test(test_leak, contents, NULL);
	if (errno && printf("leak_test: %s\n", leak_test_error(errno)) < 0)
		return (EXIT_FAILURE);
	error = !!errno;
	error |= test_func(contents);
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
