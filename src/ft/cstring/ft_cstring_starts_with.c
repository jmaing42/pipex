/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_starts_with.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:50:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:57:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

bool	ft_cstring_starts_with(
	const char *self,
	const char *substring,
	size_t *substring_length
)
{
	size_t	length;

	length = 0;
	while (*self && *substring && *self == *substring)
	{
		length++;
		self++;
		substring++;
	}
	if (substring_length)
		*substring_length = length;
	return (*substring == '\0');
}
