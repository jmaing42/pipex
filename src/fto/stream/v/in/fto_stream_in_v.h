/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_in_v.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 09:20:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_IN_V_H
# define FTO_STREAM_IN_V_H

# include "fto_stream_in.h"

t_err	fto_stream_in_v_read_all(
			t_fto_stream_in *self,
			char *buffer,
			size_t length,
			size_t *read_bytes);

#endif
