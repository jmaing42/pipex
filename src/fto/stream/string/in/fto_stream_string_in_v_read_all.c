/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_in_v_read_all.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:25:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:28:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_in_v.h"

t_err	fto_stream_string_in_v_read_all(
	t_fto_stream_string_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	*read_bytes = 0;
	while (*read_bytes < length && self->string[self->offset])
	{
		buffer[*read_bytes] = self->string[self->offset];
		(*read_bytes)++;
		self->offset++;
	}
	return (false);
}
