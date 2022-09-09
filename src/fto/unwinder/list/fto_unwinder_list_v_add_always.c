/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_v_add_always.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:40:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:43:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

t_err	fto_unwinder_list_v_add_always(
	t_fto_unwinder_list *self,
	void **destination,
	void *value,
	void (*how_to_remove_value)(void *value)
)
{
	t_fto_unwinder_list_node *const	node
		= malloc(sizeof(t_fto_unwinder_list_node));

	*destination = value;
	if (!value || !node)
	{
		how_to_remove_value(value);
		free(node);
		return (true);
	}
	node->next = self->head;
	node->value = value;
	node->how_to_remove_value = how_to_remove_value;
	node->destination = destination;
	node->remove_always = true;
	self->head = node;
	return (false);
}
