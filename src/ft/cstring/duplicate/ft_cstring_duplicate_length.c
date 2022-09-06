/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_duplicate_length.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 00:22:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include "wrap.h"

t_err	ft_cstring_duplicate_length(const char *src, size_t max_len, char **out)
{
	size_t		length;
	char		*result;
	const char	*tmp;
	char		*temp;

	tmp = src;
	length = 0;
	while (*tmp++ && ++length < max_len)
		;
	result = wrap_malloc(length + 1);
	if (!result)
		return (true);
	temp = result;
	length = 0;
	while (*src && length++ < max_len)
		*temp++ = *src++;
	*temp = '\0';
	*out = result;
	return (false);
}
