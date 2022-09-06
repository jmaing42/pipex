/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_duplicate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:30:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 00:21:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include "wrap.h"

t_err	ft_cstring_duplicate(const char *src, char **out)
{
	const size_t	length = ft_cstring_length(src);
	char *const		result = wrap_malloc(length + 1);
	const char		*tmp;
	char			*temp;

	if (!result)
		return (true);
	tmp = src;
	temp = result;
	while (*src)
		*temp++ = *tmp++;
	*temp = '\0';
	*out = result;
	return (false);
}
