/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_failed_to_alloc_new.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:13:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 10:24:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

static const t_fto_unwinder_list_vtable	g_v = {
	fto_unwinder_list_v_end_ok_failed_to_alloc,
	fto_unwinder_list_v_end_error_failed_to_alloc,
	fto_unwinder_list_v_add_failed_to_alloc,
	fto_unwinder_list_v_add_always_failed_to_alloc
};

static const t_fto_unwinder_list		g_o = {{&g_v}};

t_fto_unwinder_list	*new_fto_unwinder_list_failed_to_alloc(void)
{
	return ((t_fto_unwinder_list *)&g_o);
}
