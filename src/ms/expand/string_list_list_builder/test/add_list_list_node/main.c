/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/01 13:35:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ms_expand.h"
#include "ft_cstring.h"
#include "ft/leak_test.h"

static bool	test_leak(const void *context)
{
	t_ms_expand_string_list_list	list;

	(void)context;
	leak_test_start();
	list = (t_ms_expand_string_list_list){NULL, NULL};
	if (ms_expand_string_list_list_builder_add_list_list_node(&list))
		return (false);
	if (ms_expand_string_list_list_builder_add_list_node(&list.tail->list)
		|| ft_cstring_duplicate("Hello world!", &list.tail->list.tail->str))
	{
		ms_expand_string_list_list_free(&list);
		return (false);
	}
	ms_expand_string_list_list_builder_add_list_node(&list.tail->list);
	ms_expand_string_list_list_builder_add_list_node(&list.tail->list);
	ms_expand_string_list_list_builder_add_list_list_node(&list);
	ms_expand_string_list_list_builder_add_list_node(&list.tail->list);
	ms_expand_string_list_list_builder_add_list_list_node(&list);
	ms_expand_string_list_list_free(&list);
	return (false);
}

int	main(void)
{
	int				errno;
	t_err			error;

	errno = leak_test(test_leak, NULL, NULL);
	if (errno && printf("leak_test: %s\n", leak_test_error(errno)) < 0)
		return (EXIT_FAILURE);
	error = !!errno;
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
