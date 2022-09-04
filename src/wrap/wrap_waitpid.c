/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_waitpid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:09:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 22:10:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrap.h"

#include <sys/wait.h>

pid_t	wrap_waitpid(pid_t pid, int *stat_loc, int options)
{
	return (waitpid(pid, stat_loc, options));
}
