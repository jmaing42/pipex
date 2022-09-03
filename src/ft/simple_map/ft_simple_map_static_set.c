/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_static_set.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:01:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:50:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"

#include <stdlib.h>

#include "ft_memory.h"

static bool	ft_simple_map_static_set_internal(
	const t_ft_simple_map_static_context_set *context,
	t_ft_simple_map_static_value **current,
	size_t depth
)
{
	const size_t	index = ((unsigned char *) context->key)[depth];
	const bool		fresh = !*current;
	bool			error;

	if (fresh)
		*current = (t_ft_simple_map_static_value *)
			ft_memory_allocate(1, sizeof(t_ft_simple_map_static_value));
	if (!*current)
		return (true);
	if (depth + 1 == context->self->key_length)
	{
		if ((*current)->value[index])
			return (true);
		(*current)->value[index] = context->value;
		return (false);
	}
	error = ft_simple_map_static_set_internal(
			context,
			&(*current)->array[index],
			depth + 1);
	if (!(error && fresh))
		return (error);
	free(*current);
	*current = NULL;
	return (error);
}

bool	ft_simple_map_static_set(
	t_ft_simple_map_static *self,
	const void *key,
	void *value
)
{
	const t_ft_simple_map_static_context_set	context = {self, key, value};

	return (
		ft_simple_map_static_set_internal(
			&context,
			&self->values,
			0
		)
	);
}
