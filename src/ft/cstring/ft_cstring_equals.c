/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_equals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:59:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/13 08:00:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <stdbool.h>

bool	ft_cstring_equals(const char *a, const char *b)
{
	return (ft_cstring_compare(a, b) == 0);
}
