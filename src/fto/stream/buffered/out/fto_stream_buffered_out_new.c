/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_new.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:51:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

#include <stdlib.h>

#include "fto_stream_out_v.h"

static const struct s_fto_stream_buffered_out_vtable	g_v = {
	&fto_stream_buffered_out_v_write,
	&fto_stream_buffered_out_v_flush,
	(t_fto_stream_buffered_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_buffered_out_v_free_without_flush
};

t_fto_stream_buffered_out	*new_fto_stream_buffered_out(
	t_fto_stream_out *stream,
	bool stream_owned,
	size_t buffer_capacity
)
{
	t_fto_stream_buffered_out *const	result
		= malloc(sizeof(t_fto_stream_buffered_out) + buffer_capacity);

	if (!result)
	{
		if (stream_owned)
			stream->v->free_without_flush(stream);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stream = stream;
	result->stream_owned = stream_owned;
	result->buffer_capacity = buffer_capacity;
	result->buffer_size = 0;
	return (result);
}
