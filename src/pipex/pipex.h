/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:20:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 01:21:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <unistd.h>

# include "ft_os_file.h"

typedef struct s_pipex_node
{
	int		fd_in;
	int		fd_out;
	size_t	args_count;
	char	**args;
	char	**envp;
}	t_pipex_node;

typedef struct s_pipex
{
	size_t			node_count;
	t_ft_os_file	*in;
	t_ft_os_file	*out;
	t_pipex_node	node[];
}	t_pipex;

t_pipex	*pipex_init(size_t args_length, char **args);
t_err	pipex_new_node(t_pipex_node *out, const char *str);
void	pipex_free_node(t_pipex_node node);
void	pipex_free(t_pipex *self);
int		pipex_parent(t_pipex *self, pid_t *pids);
int		pipex_child(t_pipex *self, size_t index, char **path);

#endif
