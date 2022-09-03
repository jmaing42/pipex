/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:41:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_out_v.h"

#include <stdlib.h>
#include <unistd.h>

#include "fto_stream_out_v.h"

static const struct s_fto_stream_fd_out_vtable	g_v = {
	&fto_stream_fd_out_v_write,
	(t_fto_stream_fd_out_v_flush)(&fto_stream_out_v_flush),
	(t_fto_stream_fd_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_fd_out_v_free_without_flush,
};

t_fto_stream_fd_out	*new_fto_stream_fd_out(int fd, bool fd_owned)
{
	t_fto_stream_fd_out *const	result = malloc(sizeof(t_fto_stream_fd_out));

	if (!result)
	{
		if (fd_owned)
			close(fd);
		return (NULL);
	}
	result->v.v = &g_v;
	result->fd = fd;
	result->fd_owned = fd_owned;
	return (result);
}
