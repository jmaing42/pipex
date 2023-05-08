/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/08 17:51:33 by seonlim          ###   ########.fr       */
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
# define NO_MATCH "minishell: no matches found\n"
# define NO_FILE "minishell: No such file or directory\n"
# define INTERNAL_ERROR "minishell: internal error\n"
# define CMD_NOT_FOUNT "minishell: command not found\n"

typedef enum e_ms_execute_child_type
{
	ms_execute_child_type_redirection_in,
	ms_execute_child_type_redirection_out,
	ms_execute_child_type_command
}	t_ms_execute_child_type;

typedef struct s_ms_execute_redirections_info
{
	bool	have_redirection_in;
	bool	have_redirection_out;
}	t_ms_redirections_info;

typedef struct s_ms_execute_globals
{
	int	exit_status;
}	t_ms_execute_globals;

typedef struct s_ms_execute_cmd_pipe_info
{
	pid_t	redirection_in_pid;
	pid_t	redirection_out_pid;
	pid_t	command_pid;
	int		previous_pipe_read;
	int		pipe_write;
	int		pipe_read;
	bool	is_first;
	bool	is_last;
}	t_ms_execute_cmd_pipe_info;

typedef struct s_ms_exectue_pid_list_node
{
	struct s_ms_exectue_pid_list_node	*next;
	pid_t								pid;
}	t_ms_execute_pid_list_node;

typedef struct s_ms_execute_pid_list
{
	t_ms_execute_pid_list_node	*head;
	t_ms_execute_pid_list_node	*tail;
}	t_ms_execute_pid_list;

typedef struct s_ms_execute_pipe_info
{
	t_ms_execute_pid_list	pid_list;
	int						previous_pipe_read;
	int						pipe_write;
	int						pipe_read;
	bool					is_first;
	bool					is_last;
}	t_ms_execute_pipe_info;

typedef struct s_ms_execute_fd_list_node
{
	struct s_ms_execute_fd_list_node	*next;
	int									fd;
}	t_ms_execute_fd_list_node;

typedef struct s_ms_execute_fd_list
{
	t_ms_execute_fd_list_node	*head;
	t_ms_execute_fd_list_node	*tail;
}	t_ms_execute_fd_list;

t_ms_execute_globals	*ms_execute_globals(void);
t_err					ms_execute_program(
							t_ms_program *program);
t_err					ms_execute_and_or_list(
							t_ms_and_or_list *and_or_list);
t_err					ms_execute_pipe_list(
							t_ms_pipe_list *pipe_list);
t_err					ms_execute_pipe_and_fork(
							t_ms_execute_cmd_pipe_info *info,
							pid_t *pid);
void					ms_execute_set_signals(pid_t pid);
t_err					ms_execute_signal_message(int signo);
//child_functions
void					ms_execute_fd_exit(
							int fd,
							char *message);
void					ms_execute_command(
							t_ms_command *command,
							bool is_first,
							bool is_last);
void					ms_execute_command_simple(
							t_ms_command_simple *command);
void					ms_execute_command_compound(
							t_ms_command_compound *command);
t_err					ms_execute_redirect_in_out(
							t_ms_execute_cmd_pipe_info *info);
t_err					ms_execute_word_to_str(
							t_ms_word *word,
							char **out_path);
void					ms_execute_redirecions_in(
							t_ms_redirection_list *rd_list,
							bool is_first);
void					ms_execute_redirections_out(
							t_ms_redirection_list *rd_list,
							bool is_last);
void					ms_execute_child(
							t_ms_command *command,
							t_ms_execute_child_type type,
							bool is_first,
							bool is_last);
void					ms_execute_check_infiles(t_ms_command *command);
void					ms_execute_exit(int status, char *message);
//builtin
bool					ms_execute_builtin_check(t_ms_pipe_list *list);
void					ms_execute_builtin_run(t_ms_command *command);
#endif
