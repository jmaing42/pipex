/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:40:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:03:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "wrap.h"

void	pipex_free(t_pipex *self)
{
	size_t	i;

	i = -1;
	while (++i < self->node_count)
		pipex_free_node(self->node[i]);
	wrap_free(self);
}
