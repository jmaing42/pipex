/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines_feed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:28:41 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/15 01:28:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

t_err	ft_to_lines_feed(
	t_ft_to_lines *context,
	const void *append,
	size_t append_length
)
{
	if (context->pending)
		return (true);
	context->pending = (const char *)append;
	context->pending_offset = 0;
	context->pending_length = append_length;
	return (false);
}
