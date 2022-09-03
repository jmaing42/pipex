/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:46:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 09:21:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_IN_H
# define FTO_STREAM_IN_H

# include "ft_types.h"

# include <stddef.h>

typedef struct s_fto_stream_in
{
	const struct s_fto_stream_in_vtable	*v;
}	t_fto_stream_in;

typedef t_err	(*t_fto_stream_in_v_read)(
					t_fto_stream_in *self,
					char *buffer,
					size_t length,
					size_t *read_bytes);
typedef t_err	(*t_fto_stream_in_v_read_all)(
					t_fto_stream_in *self,
					char *buffer,
					size_t length,
					size_t *read_bytes);
typedef bool	(*t_fto_stream_in_v_end)(
					t_fto_stream_in *self);
typedef void	(*t_fto_stream_in_v_free)(
					t_fto_stream_in *self);

typedef struct s_fto_stream_in_vtable
{
	t_fto_stream_in_v_read		read;
	t_fto_stream_in_v_read_all	read_all;
	t_fto_stream_in_v_end		end;
	t_fto_stream_in_v_free		free;
}	t_fto_stream_in_vtable;

#endif
