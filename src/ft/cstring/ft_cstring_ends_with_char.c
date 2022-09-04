/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_ends_with_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:34:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:36:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

bool	ft_cstring_ends_with_char(
	const char *self,
	char expected_end
)
{
	const size_t	index = ft_cstring_find_index_reverse(self, expected_end);

	return (index != (size_t)(-1) && self[index + 1] == '\0');
}
