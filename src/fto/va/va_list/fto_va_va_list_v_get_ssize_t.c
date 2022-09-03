/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_ssize_t.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:42:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

ssize_t	fto_va_va_list_v_get_ssize_t(
	t_fto_va_va_list *self
)
{
	if (sizeof(ssize_t) < sizeof(int))
		return ((ssize_t)va_arg(*self->args, int));
	else
		return (va_arg(*self->args, ssize_t));
}
