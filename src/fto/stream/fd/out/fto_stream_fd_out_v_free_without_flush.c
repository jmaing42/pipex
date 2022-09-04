/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out_v_free_without_flush.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:41:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:02:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_out_v.h"

#include "wrap.h"

void	fto_stream_fd_out_v_free_without_flush(
	t_fto_stream_fd_out *self
)
{
	if (self->fd_owned)
		wrap_close(self->fd);
	wrap_free(self);
}
