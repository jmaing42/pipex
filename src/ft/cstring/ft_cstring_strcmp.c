/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_strcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:34:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/13 23:52:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	while (*a && *b)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	return ((int) *a - *b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	len++;
	while (--len && *a && *b)
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	if (!len)
		return (0);
	return ((int) *a - *b);
}
