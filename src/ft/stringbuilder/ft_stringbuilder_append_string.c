/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuilder_append_string.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:33:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:49:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"

#include "ft_cstring.h"

t_err	stringbuilder_append_string(t_stringbuilder *self, const char *str)
{
	return (stringbuilder_append(self, ft_cstring_length(str), str));
}
