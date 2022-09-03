/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:09:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_STRING_H
# define FTO_STREAM_STRING_H

# include "fto_stream_string_in.h"
# include "fto_stream_string_out.h"

t_err	fto_stream_string_in_v_read_all(
			t_fto_stream_string_in *self,
			char *buffer,
			size_t length,
			size_t *read_bytes);
bool	fto_stream_string_in_v_end(
			t_fto_stream_string_in *self);
void	fto_stream_string_in_v_free(
			t_fto_stream_string_in *self);
void	fto_stream_string_in_v_reset(
			t_fto_stream_string_in *self,
			const char *string,
			bool string_owned);

#endif
