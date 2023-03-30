/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:23:21 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/30 21:26:05 by seonlim          ###   ########.fr       */
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

	if (ms_expand(&command->word_list, &args))
		return (true);
	if (ms_execute_redirections(&command->redirections,
			piped_input, piped_output))
		return (true);
	
	return (false);
}
