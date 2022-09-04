/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_convert_strict.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:49:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 16:37:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_CONVERT_STRICT_H
# define FT_TYPES_CONVERT_STRICT_H

# include "ft_types.h"

t_err	ft_types_convert_strict_string_to_int(
			const char *str,
			int *out);
t_err	ft_types_convert_strict_string_to_long_double(
			const char *str,
			long double *out);

#endif
