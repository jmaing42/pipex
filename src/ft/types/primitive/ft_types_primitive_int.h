/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_primitive_int.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_PRIMITIVE_INT_H
# define FT_TYPES_PRIMITIVE_INT_H

# include <stddef.h>
# include <stdbool.h>

void	ft_types_primitive_int_swap(int *a, int *b);
int		ft_types_primitive_int_min(int a, int b);
int		ft_types_primitive_int_max(int a, int b);
int		ft_types_primitive_int_if(
			bool condition,
			int value_if_true,
			int value_if_false);

#endif
