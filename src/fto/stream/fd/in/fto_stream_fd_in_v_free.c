/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_v_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:38:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:02:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include "wrap.h"

void	fto_stream_fd_in_v_free(
	t_fto_stream_fd_in *self
)
{
	if (self->fd_owned)
		wrap_close(self->fd);
	wrap_free(self);
}
