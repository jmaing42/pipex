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
