/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:38:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/06 23:48:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_pipe.h"

#include "wrap.h"

t_err	ft_os_pipe(int *in_to_write, int *out_to_read)
{
	int	fds[2];

	if (wrap_pipe(fds) == -1)
		return (true);
	*in_to_write = fds[0];
	*out_to_read = fds[1];
	return (false);
}
