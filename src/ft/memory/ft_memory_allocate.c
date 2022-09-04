/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:09:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:53:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

#include "wrap.h"

void	*ft_memory_allocate(size_t count, size_t size)
{
	const size_t	total_size = count * size;
	void *const		result = wrap_malloc(total_size);

	if (!result)
		return (NULL);
	ft_memory_zero(result, total_size);
	return (result);
}
