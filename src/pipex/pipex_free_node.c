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
