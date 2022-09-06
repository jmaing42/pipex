/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_contains_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:14:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 00:15:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

bool	ft_cstring_contains_char(
	const char *self,
	char expected
)
{
	self--;
	while (*++self)
		if (*self == expected)
			return (true);
	return (false);
}
