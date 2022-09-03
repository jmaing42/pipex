/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:20:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 02:28:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_UNWINDER_H
# define FTO_UNWINDER_H

# include "ft_types.h"

# include <stddef.h>

typedef struct s_fto_unwinder
{
	const struct s_fto_unwinder_vtable	*v;
}	t_fto_unwinder;

typedef t_err	(*t_fto_unwinder_v_end_ok)(
					t_fto_unwinder *self);
typedef t_err	(*t_fto_unwinder_v_end_error)(
					t_fto_unwinder *self);
typedef void	*(*t_fto_unwinder_v_add)(
					t_fto_unwinder *self,
					void *value,
					void (*how_to_remove_value)(void *value));
typedef void	*(*t_fto_unwinder_v_add_always)(
					t_fto_unwinder *self,
					void *value,
					void (*how_to_remove_value)(void *value));

typedef struct s_fto_unwinder_vtable
{
	t_fto_unwinder_v_end_ok		end_ok;
	t_fto_unwinder_v_end_error	end_error;
	t_fto_unwinder_v_add		add;
	t_fto_unwinder_v_add_always	add_always;
}	t_fto_unwinder_vtable;

#endif
