/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_v_read.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:36:34 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:02:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include "wrap.h"

t_err	fto_stream_fd_in_v_read(
	t_fto_stream_fd_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	const ssize_t	result = wrap_read(self->fd, buffer, length);

	if (result == -1)
		return (true);
	*read_bytes = (size_t)result;
	if (result == 0)
		self->end = true;
	return (false);
}
