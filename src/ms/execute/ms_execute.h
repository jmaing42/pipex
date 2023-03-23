/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/03/23 22:14:06 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXECUTE_H

# include "ms.h"

# include "ft_types.h"

# define FAIL -1

typedef struct s_ms_execute_globals
{
	int	exit_status;
}	t_ms_execute_globals;

t_ms_execute_globals	*ms_execute_globals(void);

t_err					ms_execute_program(
							t_ms_program *program);
t_err					ms_execute_and_or_list(
							t_ms_and_or_list *and_or_list);
t_err					ms_execute_pipe_list(
							t_ms_pipe_list *pipe_list);
t_err					ms_execute_command(
							t_ms_command *command,
							int *piped_input,
							int *piped_output);
t_err					ms_execute_command_simple(
							t_ms_command_simple *command,
							int *piped_input,
							int *piped_output);
t_err					ms_execute_command_compound(
							t_ms_command_compound *command,
							int *piped_input,
							int *piped_output);
t_err					ms_execute_word_list(
							t_ms_word_list *word_list,
							int *piped_in,
							int *piped_out);
t_err					ms_execute_word_part_list(
							t_ms_word_part_list *wp_list);
t_err					ms_execute_word_part_string_list(
							t_ms_word_part_string_list *wps_list);
#endif
