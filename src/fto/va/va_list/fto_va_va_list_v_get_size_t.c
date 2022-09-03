/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_size_t.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:42:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

size_t	fto_va_va_list_v_get_size_t(
	t_fto_va_va_list *self
)
{
	if (sizeof(size_t) < sizeof(int))
		return ((size_t)va_arg(*self->args, unsigned int));
	else
		return (va_arg(*self->args, size_t));
}
