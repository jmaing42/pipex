/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:23:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:03:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

#include "wrap.h"

void	fto_va_va_list_v_free(
	t_fto_va_va_list *self
)
{
	if (self->va_list_owned)
		va_end(*self->args);
	wrap_free(self);
}
