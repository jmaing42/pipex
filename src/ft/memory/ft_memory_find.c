/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:42:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/13 02:20:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

bool	ft_memory_find(const void *mem, size_t size, char to_find, size_t *out)
{
	const char *const	mem_c = (char *)mem;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (mem_c[i] == to_find)
		{
			if (out)
				*out = i;
			return (true);
		}
		i++;
	}
	return (false);
}
