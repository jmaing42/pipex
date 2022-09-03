/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out_new.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:19:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:59:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"
#include "fto_stream_string_out_v.h"

#include <stdlib.h>

#include "fto_stream_out_v.h"

static const struct s_fto_stream_string_out_vtable	g_v = {
	&fto_stream_string_out_v_write,
	(t_fto_stream_string_out_v_flush)(&fto_stream_out_v_flush),
	(t_fto_stream_string_out_v_try_free)(&fto_stream_out_v_try_free),
	&fto_stream_string_out_v_free_without_flush,
	&fto_stream_string_out_v_to_string,
};

t_fto_stream_string_out	*new_fto_stream_string_out(size_t buffer_size)
{
	t_fto_stream_string_out *const	result
		= malloc(sizeof(t_fto_stream_string_out));
	t_stringbuilder *const			stringbuilder
		= new_stringbuilder(buffer_size);

	if (!result || !stringbuilder)
	{
		free(result);
		if (stringbuilder)
			stringbuilder_free(stringbuilder);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stringbuilder = stringbuilder;
	return (result);
}
