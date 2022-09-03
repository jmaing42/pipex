/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_in_v_reset.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:29:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:31:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_in_v.h"

#include <stdlib.h>

void	fto_stream_string_in_v_reset(
	t_fto_stream_string_in *self,
	const char *string,
	bool string_owned
)
{
	self->string = string;
	self->string_owned = string_owned;
}
