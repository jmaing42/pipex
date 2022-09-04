/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 05:56:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 05:57:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_PROCESS_H
# define FT_OS_PROCESS_H

# include <unistd.h>

void	ft_os_process_wait_pids(pid_t *pids, size_t count);

#endif
