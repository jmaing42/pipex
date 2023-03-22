/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:53:02 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/22 20:15:49 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXECUTE_H
# define FAIL -1
# include <unistd.h>
# include "ms.h"

typedef struct s_ms_pipe
{
	char	*infile;
	char	*outfile;
	char	**path;
	char	**envp;
	int		pid;
	int		fd[2];
	int		fd_input;
	int		cmd_num;
	int		is_here_doc;
}	t_ms_pipe;

//ms_execute.c
t_err	ms_execute(t_ms_program *program, int *out_status);
//ms_execute_pipe.c
t_err	ms_execute_pipe_list(t_ms_pipe_list *pipe_list, int *out_status);
#endif