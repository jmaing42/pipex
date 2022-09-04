/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuilder_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:33:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:56:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"

#include "wrap.h"

void	stringbuilder_free(t_stringbuilder *self)
{
	t_stringbuilder_node	*current;
	t_stringbuilder_node	*next;

	current = self->head;
	while (current)
	{
		next = current->next;
		wrap_free(current);
		current = next;
	}
	wrap_free(self);
}
