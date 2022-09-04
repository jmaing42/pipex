/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_fork_multiple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:52:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 22:05:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_fork.h"

t_err	ft_os_fork_multiple(size_t count, pid_t *out, size_t *out_index)
{
	size_t	i;

	i = -1;
	while (++i < count)
	{
		if (ft_os_fork(&out[i]))
		{
			return (true); // TODO: kill all child processes
		}
		if (out[i] == 0)
		{
			*out_index = i;
			return (false);
		}
	}
	*out_index = -1;
	return (false);
}
