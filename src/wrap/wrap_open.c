/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:09:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/12 16:10:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrap.h"

#include <stdarg.h>
#include <fcntl.h>

int	wrap_open(const char *path, int flags, ...)
{
	va_list	ap;
	int		additional_flags;

	if (flags & (O_CREAT | O_TMPFILE))
	{
		va_start(ap, flags);
		additional_flags = va_arg(ap, int);
		va_end(ap);
		return (open(path, flags, additional_flags));
	}
	return (open(path, flags));
}
