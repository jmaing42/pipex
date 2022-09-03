/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_get_unsigned_char.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:42:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

unsigned char	fto_va_va_list_v_get_unsigned_char(
	t_fto_va_va_list *self
)
{
	return ((unsigned char)va_arg(*self->args, unsigned int));
}
