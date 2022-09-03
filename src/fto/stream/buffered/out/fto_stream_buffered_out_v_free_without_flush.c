/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_v_free_without_flush.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:24:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

#include <stdlib.h>

void	fto_stream_buffered_out_v_free_without_flush(
	t_fto_stream_buffered_out *self
)
{
	if (self->stream_owned)
		self->stream->v->free_without_flush(self->stream);
	free(self);
}
