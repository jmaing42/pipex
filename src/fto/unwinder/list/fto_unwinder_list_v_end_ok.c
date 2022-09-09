/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_v_end_ok.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:32:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:35:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

t_err	fto_unwinder_list_v_end_ok(
	t_fto_unwinder_list *self
)
{
	t_fto_unwinder_list_node	*tmp;

	while (self->head)
	{
		tmp = self->head;
		self->head = tmp->next;
		if (tmp->remove_always)
		{
			if (tmp->value == *tmp->destination)
				*tmp->destination = NULL;
			tmp->how_to_remove_value(tmp->value);
		}
		free(tmp);
	}
	return (false);
}
