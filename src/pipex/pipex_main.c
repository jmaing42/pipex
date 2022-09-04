/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 08:48:49 by Juyeong Mai       #+#    #+#             */
/*   Updated: 2022/09/04 15:09:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_pipex *const	pipex = pipex_new(argc - 1, argv + 1);
	size_t			i;
	size_t			j;

	if (pipex)
	{
		printf("total %zu nodes:\n", pipex->node_count);
		i = -1;
		while (++i < pipex->node_count)
		{
			j = -1;
			while (++j < pipex->node[i].args_count)
			{
				printf("%zu:\t%s\n", j, pipex->node[i].args[j]);
			}
		}
		pipex_free(pipex);
	}
	return (0);
}
