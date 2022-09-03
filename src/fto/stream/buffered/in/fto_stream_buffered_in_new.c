/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_in_new.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:22:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/27 23:23:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_in_v.h"

#include <stdlib.h>

#include "fto_stream_in_v.h"

static const struct s_fto_stream_buffered_in_vtable	g_v = {
	&fto_stream_buffered_in_v_read_all,
	&fto_stream_buffered_in_v_read_all,
	&fto_stream_buffered_in_v_end,
	&fto_stream_buffered_in_v_free
};

t_fto_stream_buffered_in	*new_fto_stream_buffered_in(
	t_fto_stream_in *stream,
	bool stream_owned,
	size_t buffer_capacity
)
{
	t_fto_stream_buffered_in *const	result
		= malloc(sizeof(t_fto_stream_buffered_in) + buffer_capacity);

	if (!result)
	{
		if (stream_owned)
			stream->v->free(stream);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stream = stream;
	result->stream_owned = stream_owned;
	result->buffer_capacity = buffer_capacity;
	result->buffer_size = 0;
	result->buffer_offset = 0;
	return (result);
}
