/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_in_v_end.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:18:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/27 23:19:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_in_v.h"

bool	fto_stream_buffered_in_v_end(
	t_fto_stream_buffered_in *self
)
{
	return (self->stream->v->end(self->stream));
}
