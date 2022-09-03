/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:27:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 06:28:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

const char	*ft_cstring_find(const char *str, char c)
{
	str--;

	while (*++str)
		if (*str == c)
			return (str);
	return (NULL);
}
