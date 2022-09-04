/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:07:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 18:59:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include "wrap.h"
#include "ft_exit.h"

void	*ft_nonnull(void *p)
{
	if (!p)
		ft_exit(EXIT_FAILURE);
	return (p);
}

void	*ft_malloc(size_t size)
{
	return (ft_nonnull(wrap_malloc(size)));
}
