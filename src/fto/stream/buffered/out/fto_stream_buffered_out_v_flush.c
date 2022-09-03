/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_v_flush.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:15:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/27 23:01:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

t_err	fto_stream_buffered_out_v_flush(
	t_fto_stream_buffered_out *self
)
{
	size_t	wrote_bytes;
	t_err	result;

	result
		= (
			self->stream->v->write(
				self->stream,
				self->buffer,
				self->buffer_size,
				&wrote_bytes)
			|| wrote_bytes != self->buffer_size);
	self->buffer_size -= wrote_bytes;
	return (result || self->stream->v->flush(self->stream));
}
