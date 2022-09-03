/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:46:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 08:11:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

t_pipex	*pipex_new(size_t args_length, char **args)
{
	t_pipex	*result;
	size_t	i;

	if (args_length < 3)
		return (NULL);
	result = malloc(sizeof(t_pipex) + (args_length - 2) * sizeof(t_pipex_node));
	result->node_count = args_length - 2;
	result->in = NULL;
	result->out = NULL;
	i = 0;
	while (++i < args_length - 1)
	{
		if (pipex_new_node(&result->node[i - 1], args[i]))
		{
			result->node_count = i - 1;
			break ;
		}
	}
	if (result->node_count != args_length - 2)
	{
		pipex_free(result);
		return (NULL);
	}
	return (result);
}
