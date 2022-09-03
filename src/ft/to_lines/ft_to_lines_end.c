/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:05:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/13 23:38:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

char	*ft_to_lines_end(t_ft_to_lines *context)
{
	char	*result;

	result = NULL;
	if (context->current)
	{
		result = stringbuilder_to_string(context->current, 0);
		stringbuilder_free(context->current);
	}
	return (result);
}
