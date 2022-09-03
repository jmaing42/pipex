/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_duplicate_length.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 06:30:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <stdlib.h>

char	*ft_cstring_duplicate_length(const char *src, size_t max_len)
{
	size_t		length;
	char		*result;
	const char	*tmp;
	char		*temp;

	tmp = src;
	length = 0;
	while (*tmp++ && ++length < max_len)
		;
	result = (char *) malloc(length + 1);
	if (!result)
		return (NULL);
	temp = result;
	length = 0;
	while (*src && length++ < max_len)
		*temp++ = *src++;
	*temp = '\0';
	return (result);
}
