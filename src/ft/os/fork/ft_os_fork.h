/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:41:08 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 21:53:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_FORK_H
# define FT_OS_FORK_H

# include <unistd.h>

# include "ft_types.h"

t_err	ft_os_fork(pid_t *out_pid);
t_err	ft_os_fork_multiple(size_t count, pid_t *out, size_t *out_index);

#endif
