/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_double.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:41:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

double	fto_va_va_list_v_get_double(
	t_fto_va_va_list *self
)
{
	return (va_arg(*self->args, double));
}
