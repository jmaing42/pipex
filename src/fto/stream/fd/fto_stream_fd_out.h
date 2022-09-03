/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_out.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 01:00:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_FD_OUT_H
# define FTO_STREAM_FD_OUT_H

# include "fto_stream_out.h"

union u_fto_stream_fd_out_vtable
{
	const struct s_fto_stream_fd_out_vtable	*v;
	const t_fto_stream_out_vtable			*s;
};

typedef struct s_fto_stream_fd_out
{
	union u_fto_stream_fd_out_vtable	v;
	int									fd;
	bool								fd_owned;
}	t_fto_stream_fd_out;

typedef t_err	(*t_fto_stream_fd_out_v_write)(
					t_fto_stream_fd_out *self,
					const char *buffer,
					size_t length,
					size_t *wrote_bytes);
typedef t_err	(*t_fto_stream_fd_out_v_flush)(
					t_fto_stream_fd_out *self);
typedef t_err	(*t_fto_stream_fd_out_v_try_free)(
					t_fto_stream_fd_out *self);
typedef void	(*t_fto_stream_fd_out_v_free_without_flush)(
					t_fto_stream_fd_out *self);

struct s_fto_stream_fd_out_vtable
{
	t_fto_stream_fd_out_v_write					write;
	t_fto_stream_fd_out_v_flush					flush;
	t_fto_stream_fd_out_v_try_free				try_free;
	t_fto_stream_fd_out_v_free_without_flush	free_without_flush;
};

t_fto_stream_fd_out	*new_fto_stream_fd_out(int fd, bool fd_owned);

#endif
