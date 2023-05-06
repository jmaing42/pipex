/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_command_compound.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/06 18:41:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "wrap.h"
#include "ft_types.h"
#include "ft_os_fork.h"
#include "ft_exit.h"
#include "ms.h"

void	ms_execute_command_compound(t_ms_command_compound *command)
{
	if (ms_execute_and_or_list(&command->and_or_list))
		wrap_exit(EXIT_FAILURE);
	wrap_exit(ms_execute_globals()->exit_status);
}
