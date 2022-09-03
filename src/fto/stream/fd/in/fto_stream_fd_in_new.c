/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:10:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:24:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include <stdlib.h>
#include <unistd.h>

static const struct s_fto_stream_fd_in_vtable	g_v = {
	&fto_stream_fd_in_v_read,
	&fto_stream_fd_in_v_read_all,
	&fto_stream_fd_in_v_end,
	&fto_stream_fd_in_v_free,
};

t_fto_stream_fd_in	*new_fto_stream_fd_in(int fd, bool fd_owned)
{
	t_fto_stream_fd_in *const	result = malloc(sizeof(t_fto_stream_fd_in));

	if (!result)
	{
		if (fd_owned)
			close(fd);
		return (NULL);
	}
	result->v.v = &g_v;
	result->fd = fd;
	result->fd_owned = fd_owned;
	result->end = false;
	return (result);
}
