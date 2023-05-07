/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_builtin_run.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/05/07 17:17:27 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ms.h"
#include "ms_execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ms_builtin.h"
#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "wrap.h"

static void	run_builtin(t_ms_command *command, int fd)
{
	char	**args;

	if (ms_expand(&command->value.simple->word_list, &args))
		ms_execute_exit(EXIT_FAILURE, "minishell");
	if (ft_cstring_equals(args[0], "cd"))
		ms_builtin_cd(args[1]);
	else if (ft_cstring_equals(args[0], "echo"))
		ms_builtin_echo(args, fd);
	else if (ft_cstring_equals(args[0], "env"))
		ms_builtin_env(fd);
	else if (ft_cstring_equals(args[0], "exit"))
		ms_builtin_exit(args, fd);
	else if (ft_cstring_equals(args[0], "export"))
		ms_builtin_export(args);
	else if (ft_cstring_equals(args[0], "pwd"))
		ms_builtin_pwd(fd);
	else if (ft_cstring_equals(args[0], "unset"))
		ms_builtin_unset(args);
	ft_cstring_split_free(args);
}

static void	child_redirections_out(t_ms_command *command, int fd[2])
{
	if (wrap_dup2(fd[0], STDIN_FILENO) == FAIL)
		ms_execute_exit(EXIT_FAILURE, "minishell");
	wrap_close(fd[0]);
	wrap_close(fd[1]);
	if (command->type == ms_command_type_compound)
		ms_execute_redirections_out(
			&command->value.compound->redirections.out, true);
	else if (command->type == ms_command_type_simple)
		ms_execute_redirections_out(
			&command->value.simple->redirections.out, true);
	wrap_exit(EXIT_FAILURE);
}

static void	run_and_redirection_out(t_ms_command *command)
{
	pid_t	pid;
	int		fd[2];
	int		stat;

	if (wrap_pipe(fd))
		ms_execute_exit(EXIT_FAILURE, "minishell");
	pid = wrap_fork();
	if (pid == FAIL)
		ms_execute_exit(EXIT_FAILURE, "minishell");
	if (pid == CHILD_PID)
		child_redirections_out(command, fd);
	wrap_close(fd[0]);
	run_builtin(command, fd[1]);
	wrap_close(fd[1]);
	if (wrap_waitpid(pid, &stat, 0) < 0)
		ms_execute_exit(EXIT_FAILURE, "minishell");
}

void	ms_execute_builtin_run(t_ms_command *command)
{
	if (ms_execute_check_infiles(command))
	{
		perror("minishell");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return ;
	}
	if ((command->type == ms_command_type_compound
			&& command->value.compound->redirections.out.head == NULL)
		|| (command->type == ms_command_type_simple
			&& command->value.simple->redirections.out.head == NULL))
		run_builtin(command, STDOUT_FILENO);
	else
		run_and_redirection_out(command);
}
