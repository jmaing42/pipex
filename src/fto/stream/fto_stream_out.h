/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_out.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:46:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 01:00:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_OUT_H
# define FTO_STREAM_OUT_H

# include "ft_types.h"

# include <stddef.h>

typedef struct s_fto_stream_out
{
	const struct s_fto_stream_out_vtable	*v;
}	t_fto_stream_out;

typedef t_err	(*t_fto_stream_out_v_write)(
					t_fto_stream_out *self,
					const char *buffer,
					size_t length,
					size_t *wrote_bytes);
typedef t_err	(*t_fto_stream_out_v_flush)(
					t_fto_stream_out *self);
typedef t_err	(*t_fto_stream_out_v_try_free)(
					t_fto_stream_out *self);
typedef void	(*t_fto_stream_out_v_free_without_flush)(
					t_fto_stream_out *self);

typedef struct s_fto_stream_out_vtable
{
	t_fto_stream_out_v_write				write;
	t_fto_stream_out_v_flush				flush;
	t_fto_stream_out_v_try_free				try_free;
	t_fto_stream_out_v_free_without_flush	free_without_flush;
}	t_fto_stream_out_vtable;

#endif
