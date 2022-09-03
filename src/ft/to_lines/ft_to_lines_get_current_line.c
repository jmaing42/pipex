/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines_get_current_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:35:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/15 01:37:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

t_err	ft_to_lines_get_current_line(
	t_ft_to_lines *context,
	char **out_line,
	size_t *out_line_length
)
{
	if (!context->current)
	{
		*out_line = NULL;
		return (false);
	}
	*out_line = stringbuilder_to_string(context->current, 0);
	if (!*out_line)
		return (true);
	*out_line_length = context->current->length;
	return (false);
}
