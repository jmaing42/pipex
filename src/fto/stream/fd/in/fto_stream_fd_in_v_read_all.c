/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_v_read_all.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:36:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:39:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include <unistd.h>

t_err	fto_stream_fd_in_v_read_all(
	t_fto_stream_fd_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	ssize_t	read_result;

	*read_bytes = 0;
	while (!self->end && *read_bytes != length)
	{
		read_result = read(self->fd, buffer, length - *read_bytes);
		if (read_result == -1)
			return (true);
		if (read_result == 0)
			self->end = true;
		*read_bytes += read_result;
	}
	return (false);
}
