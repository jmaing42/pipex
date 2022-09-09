/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_v_add_failed_to_alloc.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:19:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:24:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

t_err	fto_unwinder_list_v_add_failed_to_alloc(
	t_fto_unwinder_list *self,
	void **destination,
	void *value,
	void (*how_to_remove_value)(void *value)
)
{
	(void)self;
	how_to_remove_value(value);
	*destination = NULL;
	return (true);
}
