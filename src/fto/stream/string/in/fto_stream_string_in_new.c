/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_in_new.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:10:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:23:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"
#include "fto_stream_string_in_v.h"

#include <stdlib.h>

#include "fto_stream_in_v.h"

static const struct s_fto_stream_string_in_vtable	g_v = {
	&fto_stream_string_in_v_read_all,
	&fto_stream_string_in_v_read_all,
	&fto_stream_string_in_v_end,
	&fto_stream_string_in_v_free,
	&fto_stream_string_in_v_reset,
};

t_fto_stream_string_in	*new_fto_stream_string_in(
	const char *string,
	bool string_owned
)
{
	t_fto_stream_string_in *const	result
		= malloc(sizeof(t_fto_stream_string_in));

	if (!result)
	{
		if (string_owned)
			free((void *)string);
		return (NULL);
	}
	result->v.v = &g_v;
	result->string = string;
	result->string_owned = string_owned;
	result->offset = 0;
	return (result);
}
