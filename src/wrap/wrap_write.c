/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:09:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:09:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrap.h"

ssize_t	wrap_write(int fd, const void *buffer, size_t bytes)
{
	return (write(fd, buffer, bytes));
}
