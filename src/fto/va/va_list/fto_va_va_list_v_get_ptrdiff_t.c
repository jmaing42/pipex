/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_ptrdiff_t.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:41:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

ptrdiff_t	fto_va_va_list_v_get_ptrdiff_t(
	t_fto_va_va_list *self
)
{
	if (sizeof(ptrdiff_t) < sizeof(int))
		return ((ptrdiff_t)va_arg(*self->args, int));
	else
		return (va_arg(*self->args, ptrdiff_t));
}
