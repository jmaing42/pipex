/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXECUTE_H

# include "ms.h"

# include <stdbool.h>
# include <sys/_types/_pid_t.h>

# include "ft_types.h"
# include "ft_stringbuilder.h"
# include "ms_expand.h"

# define FAIL -1
# define READ_BUF_SIZE 10
# define CHILD_PID 0

typedef struct s_ms_execute_globals
{
	int	exit_status;
}	t_ms_execute_globals;

typedef struct s_ms_execute_pipe_info
{
	pid_t	redirection_in_pid;
	pid_t	redirection_out_pid;
	pid_t	command_pid;
	int		previous_pipe_read;
	int		pipe_write;
	int		pipe_read;
	bool	is_first;
}	t_ms_execute_pipe_info;

t_ms_execute_globals	*ms_execute_globals(void);

t_err					ms_execute_program(
							t_ms_program *program);
t_err					ms_execute_and_or_list(
							t_ms_and_or_list *and_or_list);
t_err					ms_execute_pipe_list(
							t_ms_pipe_list *pipe_list);
t_err					ms_execute_command(
							t_ms_command *command,
							t_ms_execute_pipe_info *info);
void					ms_execute_command_simple(
							t_ms_command_simple *command);
void					ms_execute_command_compound(
							t_ms_command_compound *command);
t_err					ms_execute_redirect_in_out(
							t_ms_execute_pipe_info *info);
t_err					ms_execute_redirections_word_to_str(
							t_ms_word *word,
							char **out_path);
void					ms_execute_redirecions_in(
							t_ms_redirection_list *rd_list,
							bool is_first);
void					ms_execute_redirections_out(
							t_ms_redirection_list *rd_list);
t_err					ms_execute_pipe_and_fork(
							t_ms_execute_pipe_info *info,
							pid_t *pid);
#endif
