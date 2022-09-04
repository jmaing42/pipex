/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:38:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 04:39:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_pipe.h"
#include <unistd.h>

t_err	ft_os_pipe(int *to_read, int *to_write)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (true);
	*to_read = fds[0];
	*to_write = fds[1];
	return (false);
}