/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_v_end_error.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:32:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:35:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

t_err	fto_unwinder_list_v_end_error(
	t_fto_unwinder_list *self
)
{
	t_fto_unwinder_list_node	*tmp;

	while (self->head)
	{
		tmp = self->head;
		self->head = tmp->next;
		if (tmp->value == *tmp->destination)
			*tmp->destination = NULL;
		tmp->how_to_remove_value(tmp->value);
		free(tmp);
	}
	return (true);
}
