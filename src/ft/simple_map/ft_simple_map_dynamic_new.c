/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_map_dynamic_new.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:18:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:55:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_map_internal.h"
#include "ft_simple_map.h"

#include "ft_memory.h"

t_ft_simple_map_dynamic	*new_ft_simple_map_dynamic(void)
{
	return ((t_ft_simple_map_dynamic *)
		ft_memory_allocate(1, sizeof(t_ft_simple_map_dynamic)));
}
