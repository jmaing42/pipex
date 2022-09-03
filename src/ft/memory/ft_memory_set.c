/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:09:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:32:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memory_set(void *mem, int value, size_t len)
{
	char	*ptr;

	ptr = (char *) mem;
	while (len--)
		*ptr++ = (signed char) value;
	return (mem);
}
