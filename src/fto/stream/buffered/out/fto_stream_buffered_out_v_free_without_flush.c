/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_v_free_without_flush.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:24:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:01:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

#include "wrap.h"

void	fto_stream_buffered_out_v_free_without_flush(
	t_fto_stream_buffered_out *self
)
{
	if (self->stream_owned)
		self->stream->v->free_without_flush(self->stream);
	wrap_free(self);
}
