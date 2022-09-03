/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:05:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/15 01:41:18 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

void	ft_to_lines_free(t_ft_to_lines *context)
{
	if (context->current)
	{
		stringbuilder_free(context->current);
		context->current = NULL;
	}
	context->pending = NULL;
}
