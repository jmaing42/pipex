/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:09:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:31:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

#include <stdlib.h>

void	*ft_memory_duplicate(const void *source, size_t size)
{
	void *const	result = malloc(size);

	if (!result)
		return (NULL);
	ft_memory_copy(result, source, size);
	return (result);
}
