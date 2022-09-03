/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_v_clone.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:20:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:22:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list_v.h"

#include "fto_va_va_list.h"

t_fto_va_va_list	*fto_va_va_list_v_clone(
	t_fto_va_va_list *self
)
{
	return (new_fto_va_va_list(self->args, true));
}
