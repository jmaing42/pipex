/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:32:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BYTE_MAP_H
# define FT_BYTE_MAP_H

# include <stdarg.h>

# include "ft_types.h"

/**
 * @brief bake map for single set
 *
 * @param map out parameter to get result
 * @param include_null indicate whether include NULL
 * @param set input
 */
void	ft_byte_map(t_byte *map, bool include_null, const t_byte *set);

/**
 * @brief bake map for multiple set
 *
 * @param map out parameter to get result
 * @param include_null indicate whether include NULL
 * @param arguments va_list contains multiple sets with trailing NULL
 */
void	ft_byte_map_v(t_byte *map, bool include_null, va_list arguments);

/**
 * @brief bake map for multiple set
 *
 * @remarks include_null is not bool because passing an object that undergoes
 *		default argument promotion to 'va_start' has undefined behavior
 *
 * @param map out parameter to get result
 * @param include_null indicate whether include NULL
 * @param ... multiple sets with trailing NULL
 */
void	ft_byte_map_va(t_byte *map, int include_null, ...);

#endif
