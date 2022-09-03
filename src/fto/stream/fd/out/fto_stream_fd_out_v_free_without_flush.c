/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out_v_free_without_flush.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:41:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_out_v.h"

#include <stdlib.h>
#include <unistd.h>

void	fto_stream_fd_out_v_free_without_flush(
	t_fto_stream_fd_out *self
)
{
	if (self->fd_owned)
		close(self->fd);
	free(self);
}
