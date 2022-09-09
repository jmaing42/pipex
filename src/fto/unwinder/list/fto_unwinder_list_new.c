/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:08:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:13:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

static const t_fto_unwinder_list_vtable	g_v = {
	fto_unwinder_list_v_end_ok,
	fto_unwinder_list_v_end_error,
	fto_unwinder_list_v_add,
	fto_unwinder_list_v_add_always
};

t_fto_unwinder_list	*fto_unwinder_list_new(void)
{
	t_fto_unwinder_list *const	result = malloc(sizeof(t_fto_unwinder_list));

	if (!result)
		return (fto_unwinder_list_new_failed_to_alloc());
	result->v.v = &g_v;
	result->head = NULL;
	return (result);
}
