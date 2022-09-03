/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:42:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/15 01:43:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

void	ft_to_lines_init(
	t_ft_to_lines *context,
	size_t buffer_size
)
{
	context->current = NULL;
	context->pending = NULL;
	context->buffer_size = buffer_size;
}
