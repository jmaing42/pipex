/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_new_failed_to_alloc.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:13:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:22:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

static const t_fto_unwinder_list_vtable	g_v = {
	fto_unwinder_list_v_end_ok_failed_to_alloc,
	fto_unwinder_list_v_end_error_failed_to_alloc,
	fto_unwinder_list_v_add_failed_to_alloc,
	fto_unwinder_list_v_add_failed_to_alloc,
};

static const t_fto_unwinder_list		g_o = {{&g_v}, NULL};

t_fto_unwinder_list	*fto_unwinder_list_new_failed_to_alloc(void)
{
	return ((t_fto_unwinder_list *)&g_o);
}
