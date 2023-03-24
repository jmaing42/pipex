/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:23:21 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/24 20:31:44 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdbool.h>
#include <stdlib.h>

#include "ft_types.h"
#include "ft_os_pipe.h"
#include "ms.h"

t_err	ms_execute_command_simple(
	t_ms_command_simple *command,
	int *piped_input,
	int *piped_output
)
{
	char	**args;
	
	args = NULL;
	(void)piped_input; (void)piped_output;
	return (ms_execute_word_list(&command->word_list,
			args));
}
