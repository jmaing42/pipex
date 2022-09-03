/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:40:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_FD_IN_H
# define FTO_STREAM_FD_IN_H

# include "fto_stream_in.h"

union u_fto_stream_fd_in_vtable
{
	const struct s_fto_stream_fd_in_vtable	*v;
	const t_fto_stream_in_vtable			*s;
};

typedef struct s_fto_stream_fd_in
{
	union u_fto_stream_fd_in_vtable	v;
	int								fd;
	bool							fd_owned;
	bool							end;
}	t_fto_stream_fd_in;

typedef t_err	(*t_fto_stream_fd_in_v_read)(
					t_fto_stream_fd_in *self,
					char *buffer,
					size_t length,
					size_t *read_bytes);
typedef t_err	(*t_fto_stream_fd_in_v_read_all)(
					t_fto_stream_fd_in *self,
					char *buffer,
					size_t length,
					size_t *read_bytes);
typedef bool	(*t_fto_stream_fd_in_v_end)(
					t_fto_stream_fd_in *self);
typedef void	(*t_fto_stream_fd_in_v_free)(
					t_fto_stream_fd_in *self);

struct s_fto_stream_fd_in_vtable
{
	t_fto_stream_fd_in_v_read		read;
	t_fto_stream_fd_in_v_read_all	read_all;
	t_fto_stream_fd_in_v_end		end;
	t_fto_stream_fd_in_v_free		free;
};

t_fto_stream_fd_in	*new_fto_stream_fd_in(int fd, bool fd_owned);

#endif
