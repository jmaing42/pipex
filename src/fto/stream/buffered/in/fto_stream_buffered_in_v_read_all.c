/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_in_v_read_all.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:59:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 08:57:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_in_v.h"

#include "ft_memory.h"
#include "ft_types_primitive_size_t.h"

static t_err	fill_buffer(
	t_fto_stream_buffered_in *self
)
{
	return (
		!self->buffer_offset
		&& self->stream->v->read(
			self->stream,
			self->buffer,
			self->buffer_capacity,
			&self->buffer_size
		)
	);
}

static size_t	feed(
	t_fto_stream_buffered_in *self,
	size_t limit,
	void *buffer
)
{
	const size_t	remain = self->buffer_size - self->buffer_offset;
	const size_t	to_feed = ft_types_primitive_size_t_max(remain, limit);

	ft_memcpy(buffer, self->buffer + self->buffer_offset, to_feed);
	self->buffer_offset += to_feed;
	if (self->buffer_offset == self->buffer_size)
	{
		self->buffer_offset = 0;
		self->buffer_size = 0;
	}
	return (to_feed);
}

t_err	fto_stream_buffered_in_v_read_all(
	t_fto_stream_buffered_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	*read_bytes = 0;
	while (*read_bytes < length && !fto_stream_buffered_in_v_end(self))
	{
		if (fill_buffer(self))
			return (true);
		*read_bytes += feed(self, length - *read_bytes, buffer);
	}
	return (false);
}
