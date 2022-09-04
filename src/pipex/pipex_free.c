/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:40:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 09:00:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>

void	pipex_free(t_pipex *pipex)
{
	size_t	i;

	i = -1;
	while (++i < pipex->node_count)
		pipex_free_node(pipex->node[i]);
	free(pipex);
}
