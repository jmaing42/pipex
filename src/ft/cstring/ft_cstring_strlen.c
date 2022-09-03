/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_strlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:00:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 06:34:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <limits.h>

#include "ft_byte_map.h"

size_t	ft_strlen_until_set(
	const char *str,
	const char *set,
	bool include_null
)
{
	t_byte	map[1 << CHAR_BIT];

	ft_byte_map(map, include_null, (t_byte *) set);
	return (ft_strlen_until_map(str, map));
}

size_t	ft_strlen_until_map(
	const char *str,
	const t_byte *map
)
{
	size_t	result;

	result = 0;
	while (!map[*((t_byte *) str)])
	{
		str++;
		result++;
	}
	return (result);
}
