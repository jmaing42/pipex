/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:40:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 01:29:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "wrap.h"

#include "ft_cstring_split.h"

void	pipex_free_node(t_pipex_node node)
{
	if (node.fd_in != -1)
		wrap_close(node.fd_in);
	if (node.fd_out != -1)
		wrap_close(node.fd_out);
	if (node.args)
		ft_cstring_split_free(node.args);
	// if (node.envp)
	// 	ft_cstring_split_free(node.envp);
}
