/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_process_wait_pids.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 05:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 05:27:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_process.h"

#include <sys/wait.h>

#include "wrap.h"

int	ft_os_process_wait_pids(pid_t *pids, size_t count)
{
	size_t	i;
	int		last_stat_loc;

	i = -1;
	while (++i < count)
		wrap_waitpid(pids[i], &last_stat_loc, 0);
	return (WEXITSTATUS(last_stat_loc));
}
