/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:50:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 21:06:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	assert(bool must_be_true, const char *message)
{
	if (!must_be_true)
	{
		puts(message);
		exit(EXIT_FAILURE);
	}
}

void	assert_str_eq(char *actual, char *expected)
{
	assert(actual && expected, "One of string is NULL");
	if (strcmp(actual, expected) != 0)
	{
		printf(
			"Given two strings are not equal:\n\tactual: %s\n\texpected: %s\n",
			actual, expected);
		exit(EXIT_FAILURE);
	}
}

void	assert_null(void *must_be_null)
{
	assert(must_be_null == NULL, "Given value is not NULL");
}

void	assert_not_null(void *must_not_be_null)
{
	assert(must_not_be_null != NULL, "Given value is NULL");
}
