/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_uintmax_t.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:42:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

uintmax_t	fto_va_va_list_v_get_uintmax_t(
	t_fto_va_va_list *self
)
{
	return (va_arg(*self->args, uintmax_t));
}
