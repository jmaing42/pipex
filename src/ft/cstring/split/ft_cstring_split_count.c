/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_split_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:28:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 05:34:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring_split.h"

#include "ft_cstring.h"

size_t	ft_cstring_split_count(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	str = ft_cstring_find_one_of(str, charset, true);
	while (*str)
	{
		length++;
		str = ft_cstring_find_one_of(str, charset, false);
		if (!*str)
			break ;
		str = ft_cstring_find_one_of(str, charset, true);
	}
	return (length);
}
