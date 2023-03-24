/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_double_alloc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:17:06 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 22:18:58 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"

char	**ms_execute_double_alloc(char **out_arr, int *capacity)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * 2 * *capacity);
	if (tmp == NULL)
	{
		i = -1;
		while (++i < *capacity)
			free(out_arr[i]);
		free(out_arr);
		return (NULL);
	}
	i = 0;
	while (i < *capacity)
	{
		tmp[i] = out_arr[i];
		i++;
	}
	free(out_arr);
	*capacity *= 2;
	return (tmp);
}
