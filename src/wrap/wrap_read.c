/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:09:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:09:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrap.h"

ssize_t	wrap_read(int fd, void *buffer, size_t bytes)
{
	return (read(fd, buffer, bytes));
}
