/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_primitive_size_t.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_PRIMITIVE_SIZE_T_H
# define FT_TYPES_PRIMITIVE_SIZE_T_H

# include <stddef.h>
# include <stdbool.h>

void	ft_types_primitive_size_t_swap(size_t *a, size_t *b);
size_t	ft_types_primitive_size_t_min(size_t a, size_t b);
size_t	ft_types_primitive_size_t_max(size_t a, size_t b);
size_t	ft_types_primitive_size_t_if(
			bool condition,
			size_t value_if_true,
			size_t value_if_false);

#endif
