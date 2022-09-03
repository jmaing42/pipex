/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out_v.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:37:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_STRING_OUT_V_H
# define FTO_STREAM_STRING_OUT_V_H

# include "fto_stream_string_out.h"

t_err	fto_stream_string_out_v_write(
			t_fto_stream_string_out *self,
			const char *buffer,
			size_t length,
			size_t *wrote_bytes);
void	fto_stream_string_out_v_free_without_flush(
			t_fto_stream_string_out *self);
char	*fto_stream_string_out_v_to_string(
			t_fto_stream_string_out *self,
			size_t *length);

#endif
