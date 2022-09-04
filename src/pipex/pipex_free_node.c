/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:40:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 15:24:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring_split.h"

void	pipex_free_node(t_pipex_node node)
{
	if (node.fd_in != -1)
		close(node.fd_in);
	if (node.fd_out != -1)
		close(node.fd_out);
	free(node.path);
	if (node.args)
		ft_cstring_split_free(node.args);
	if (node.envp)
		ft_cstring_split_free(node.envp);
}
