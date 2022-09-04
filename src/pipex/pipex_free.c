/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:40:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 20:10:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_file.h"
#include "pipex.h"

#include "wrap.h"

void	pipex_free(t_pipex *self)
{
	size_t	i;

	i = -1;
	while (++i < self->node_count)
		pipex_free_node(self->node[i]);
	if (self->in)
		ft_os_file_close(self->in);
	if (self->out)
		ft_os_file_close(self->out);
	wrap_free(self);
}
