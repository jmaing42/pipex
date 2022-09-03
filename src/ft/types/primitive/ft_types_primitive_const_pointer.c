/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_primitive_const_pointer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types_primitive_const_pointer.h"

void	ft_types_primitive_const_pointer_swap(const void **a, const void **b)
{
	const void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

const void	*ft_types_primitive_const_pointer_if(
	bool condition,
	const void *value_if_true,
	const void *value_if_false
)
{
	if (condition)
		return (value_if_true);
	return (value_if_false);
}
