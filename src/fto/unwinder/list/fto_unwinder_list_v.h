/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list_v.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:05:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 10:12:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_UNWINDER_LIST_V_H
# define FTO_UNWINDER_LIST_V_H

# include "fto_unwinder_list.h"

t_err				fto_unwinder_list_v_end_ok(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_end_error(
						t_fto_unwinder_list *self);
void				*fto_unwinder_list_v_add(
						t_fto_unwinder_list *self,
						void *value,
						void (*how_to_remove_value)(void *value));
void				*fto_unwinder_list_v_add_always(
						t_fto_unwinder_list *self,
						void *value,
						void (*how_to_remove_value)(void *value));

t_err				fto_unwinder_list_v_end_ok_failed_to_alloc(
						t_fto_unwinder_list *self);
t_err				fto_unwinder_list_v_end_error_failed_to_alloc(
						t_fto_unwinder_list *self);
void				*fto_unwinder_list_v_add_failed_to_alloc(
						t_fto_unwinder_list *self,
						void *value,
						void (*how_to_remove_value)(void *value));
void				*fto_unwinder_list_v_add_always_failed_to_alloc(
						t_fto_unwinder_list *self,
						void *value,
						void (*how_to_remove_value)(void *value));

t_fto_unwinder_list	*new_fto_unwinder_list_failed_to_alloc(void);

#endif
