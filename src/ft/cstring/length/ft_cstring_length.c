/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:34:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 06:34:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

size_t	ft_cstring_length(const char *str)
{
	size_t	result;

	result = 0;
	while (*str)
	{
		str++;
		result++;
	}
	return (result);
}
