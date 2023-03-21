/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:53:02 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/20 22:40:08 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXCUTE_H
# define FAIL -1
# include "ms.h"

typedef struct s_ms_pipe
{
	char	*infile;
	char	*outfile;
	char	**path;
	char	**envp;
	t_cmd	*cmd;
	t_cmd	*cmd_back;
	int		pid;
	int		fd[2];
	int		fd_input;
	int		cmd_num;
	int		is_here_doc;
}	t_ms_pipe;

#endif