/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_v_end.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:38:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:41:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include <stdlib.h>
#include <unistd.h>

bool	fto_stream_fd_in_v_end(
	t_fto_stream_fd_in *self
)
{
	return (self->end);
}
