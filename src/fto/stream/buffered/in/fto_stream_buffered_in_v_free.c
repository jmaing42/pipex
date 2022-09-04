/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_in_v_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:20:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:59:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_in_v.h"

#include "wrap.h"

void	fto_stream_buffered_in_v_free(
	t_fto_stream_buffered_in *self
)
{
	if (self->stream_owned)
		self->stream->v->free(self->stream);
	wrap_free(self);
}
