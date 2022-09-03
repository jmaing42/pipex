/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_find_one_of.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:29:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 05:29:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

const char	*ft_cstring_find_one_of(
	const char *str,
	const char *charset,
	bool negate
)
{
	const char	*tmp;

	str--;
	while (*++str)
	{
		tmp = charset - 1;
		if (negate)
		{
			while (*++tmp)
				if (*tmp == *str)
					break ;
			if (!*tmp)
				return (str);
		}
		else
		{
			while (*++tmp)
				if (*tmp == *str)
					return (str);
		}
	}
	return (str);
}
