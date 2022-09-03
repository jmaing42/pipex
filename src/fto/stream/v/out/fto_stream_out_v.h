/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_out_v.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:55:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 08:56:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_OUT_V_H
# define FTO_STREAM_OUT_V_H

# include "fto_stream_out.h"

t_err	fto_stream_out_v_flush(
			t_fto_stream_out *self);
t_err	fto_stream_out_v_try_free(
			t_fto_stream_out *self);

#endif
