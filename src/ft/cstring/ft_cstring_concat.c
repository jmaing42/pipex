/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_concat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:26:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:52:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include "wrap.h"

#include "ft_memory.h"

char	*ft_cstring_concat(const char *a, const char *b)
{
	const size_t	a_length = ft_cstring_length(a);
	const size_t	b_length = ft_cstring_length(b);
	char *const		result = wrap_malloc(a_length + b_length + 1);

	if (!result)
		return (NULL);
	ft_memory_copy(result, a, a_length);
	ft_memory_copy(result + a_length, b, b_length);
	result[a_length + b_length] = '\0';
	return (result);
}
