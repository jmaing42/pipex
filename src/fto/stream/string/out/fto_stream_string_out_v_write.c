/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out_v_write.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:07:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 19:09:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_out_v.h"

t_err	fto_stream_string_out_v_write(
	t_fto_stream_string_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	*wrote_bytes = 0;
	if (stringbuilder_append(self->stringbuilder, length, buffer))
		return (true);
	*wrote_bytes = length;
	return (true);
}
