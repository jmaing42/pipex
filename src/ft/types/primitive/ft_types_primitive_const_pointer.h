/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_primitive_const_pointer.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 16:18:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_PRIMITIVE_CONST_POINTER_H
# define FT_TYPES_PRIMITIVE_CONST_POINTER_H

# include <stdbool.h>

void		ft_types_primitive_const_pointer_swap(
				const void **a,
				const void **b);
const void	*ft_types_primitive_const_pointer_if(
				bool condition,
				const void *value_if_true,
				const void *value_if_false);

#endif
