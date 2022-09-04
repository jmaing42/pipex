/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_static_new.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:01:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:55:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"
#include "ft_simple_map.h"

#include "wrap.h"

t_ft_simple_map_static	*new_ft_simple_map_static(size_t key_length)
{
	t_ft_simple_map_static	*result;

	if (!key_length)
		return (NULL);
	result
		= (t_ft_simple_map_static *)wrap_malloc(sizeof(t_ft_simple_map_static));
	if (!result)
		return (NULL);
	result->key_length = key_length;
	result->values = NULL;
	return (result);
}
