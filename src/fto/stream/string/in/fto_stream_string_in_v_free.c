/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_in_v_free.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:29:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:03:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_in_v.h"

#include "wrap.h"

void	fto_stream_string_in_v_free(
	t_fto_stream_string_in *self
)
{
	if (self->string_owned)
		wrap_free((void *)self->string);
	wrap_free(self);
}
