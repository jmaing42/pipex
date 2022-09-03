/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:10:23 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 08:06:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "ft_os_pipe.h"

extern char	**environ;

t_err	pipex_new_node(t_pipex_node *out, const char *str)
{
	t_pipex_node	result;
	const size_t	args_count = ft_cstring_split_count(str, "\t\n\v\f\r ");

	if (ft_os_pipe(&result.fd_in, &result.fd_out))
		return (true);
	result.path = NULL;
	result.args_count = args_count;
	result.args = ft_cstring_split(str, "\t\n\v\f\r ");
	result.envp = environ;
	if (!result.args)
	{
		pipex_free_node(result);
		return (true);
	}
	*out = result;
	return (false);
}
