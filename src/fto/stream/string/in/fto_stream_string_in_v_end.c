/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_in_v_end.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:29:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:30:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_in_v.h"

bool	fto_stream_string_in_v_end(
	t_fto_stream_string_in *self
)
{
	return (!self->string[self->offset]);
}
