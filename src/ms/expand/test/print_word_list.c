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

#include "ms_expand.h"
#include "ft_cstring_split.h"

t_err	print_word_list(t_ms_word_list *word_list)
{
	char	**argv;
	size_t	i;
	t_err	result;

	if (ms_expand(word_list, &argv))
		return (true);
	i = -1;
	result = false;
	while (argv[++i])
		if (printf("[%zu] %s\n", i, argv[i]) < 0)
			result = true;
	ft_cstring_split_free(argv);
	return (result);
}
