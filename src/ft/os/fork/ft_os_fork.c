/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:42:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:44:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_fork.h"

#include "wrap.h"

t_err	ft_os_fork(pid_t *out_pid)
{
	const pid_t	pid = wrap_fork();

	if (pid == -1)
		return (true);
	*out_pid = pid;
	return (false);
}
