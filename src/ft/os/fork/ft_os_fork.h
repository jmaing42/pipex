/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:41:08 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 19:44:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_FORK_H
# define FT_OS_FORK_H

# include <unistd.h>

# include "ft_types.h"

t_err	ft_os_fork(pid_t *out_pid);

#endif
