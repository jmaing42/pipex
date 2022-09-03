/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_in_v_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:20:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/27 23:21:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_in_v.h"

#include <stdlib.h>

void	fto_stream_buffered_in_v_free(
	t_fto_stream_buffered_in *self
)
{
	if (self->stream_owned)
		self->stream->v->free(self->stream);
	free(self);
}
