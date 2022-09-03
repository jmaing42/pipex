/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out_v_write.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:41:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 09:02:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_out_v.h"

#include <unistd.h>

#ifndef WRITE_SIZE_MAX
# define WRITE_SIZE_MAX 1048576
#else
# if WRITE_SIZE_MAX < 1
#  error WRITE_SIZE_MAX is too small
# endif
#endif

t_err	fto_stream_fd_out_v_write(
	t_fto_stream_fd_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	size_t		remain;
	size_t		to_write;
	ssize_t		wrote;
	const char	*str;

	str = (const char *)buffer;
	remain = length;
	while (remain)
	{
		to_write = remain;
		if (to_write > WRITE_SIZE_MAX)
			to_write = WRITE_SIZE_MAX;
		wrote = write(self->fd, str, to_write);
		if (wrote < 0)
		{
			if (wrote_bytes)
				*wrote_bytes = length - remain;
			return (true);
		}
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	if (wrote_bytes)
		*wrote_bytes = length;
	return (false);
}
