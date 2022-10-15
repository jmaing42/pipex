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

#include <stdio.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ms_parse.h"

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

static t_err	print_token_type(t_ms_parse_token_type type)
{
	if (type == MS_PARSE_TOKEN_TYPE_EOF)
		return (printf("EOF") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_AND)
		return (printf("AND") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_OR)
		return (printf("OR") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_LEFT_CHEVRON)
		return (printf("LEFT_CHEVRON") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_RIGHT_CHEVRON)
		return (printf("RIGHT_CHEVRON") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_LEFT_PARENTHESIS)
		return (printf("LEFT_PARENTHESIS") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_RIGHT_PARENTHESIS)
		return (printf("RIGHT_PARENTHESIS") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_SPACE)
		return (printf("SPACE") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_WORD)
		return (printf("WORD") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED)
		return (printf("WORD_QUOTED") < 0);
	if (type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
		return (printf("WORD_DOUBLE_QUOTED") < 0);
	return (true);
}

static t_err	print_token(t_ms_parse_token token)
{
	if (print_token_type(token.type))
		return (true);
	if (token.type == MS_PARSE_TOKEN_TYPE_WORD
		|| token.type == MS_PARSE_TOKEN_TYPE_WORD_QUOTED
		|| token.type == MS_PARSE_TOKEN_TYPE_WORD_DOUBLE_QUOTED)
		return (printf(" - %s\n", token.data) < 0);
	else
		return (printf("\n") < 0);
}

int	main(int argc, char **argv)
{
	char						*contents;
	t_ms_parse_token_list		list;
	t_ms_parse_token_list_node	*node;

	if (argc < 2 || read_file_contents(argv[1], &contents))
		return (true);
	if (ms_parse_tokenize(contents, &list))
	{
		free(contents);
		return (EXIT_FAILURE);
	}
	node = list.head;
	while (node)
	{
		if (print_token(node->value))
		{
			ms_parse_tokenize_free(&list);
			return (EXIT_FAILURE);
		}
		node = node->next;
	}
	ms_parse_tokenize_free(&list);
	return (EXIT_SUCCESS);
}
