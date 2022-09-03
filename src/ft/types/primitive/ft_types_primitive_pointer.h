/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_primitive_pointer.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_PRIMITIVE_POINTER_H
# define FT_TYPES_PRIMITIVE_POINTER_H

# include <stdbool.h>

void	ft_types_primitive_pointer_swap(void **a, void **b);
void	*ft_types_primitive_pointer_if(
			bool condition,
			void *value_if_true,
			void *value_if_false);

#endif
