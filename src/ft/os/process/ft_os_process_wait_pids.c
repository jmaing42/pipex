/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_process_wait_pids.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 05:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 06:03:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_process.h"

#include "wrap.h"

void	ft_os_process_wait_pids(pid_t *pids, size_t count)
{
	size_t	i;
	int		unused_stat_loc;

	i = -1;
	while (++i < count)
		wrap_waitpid(pids[i], &unused_stat_loc, 0);
}
