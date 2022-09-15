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

#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "ft_os_pipe.h"
#include "ft_os_util_envp.h"

char	**init_environment(const char *const *environ)
{
	// t_ft_os_util_envp_builder *const	builder
	// 	= new_ft_os_util_envp_builder(environ);
	// char								**result;

	// if (!builder)
	// 	return (NULL);
	// result = ft_os_util_envp_builder_build(builder);
	// ft_os_util_envp_builder_free(builder);
	// return (result);
	return ((char **)environ);
}

t_err	pipex_new_node(t_pipex_node *out, const char *str, size_t index)
{
	t_pipex_node	result;
	const size_t	args_count = ft_cstring_split_count(str, "\t\n\v\f\r ");

	if (index != 0 && ft_os_pipe(&result.fd_in, &result.fd_out))
		return (true);
	if (index == 0)
	{
		result.fd_in = -1;
		result.fd_out = -1;
	}
	result.args_count = args_count;
	result.args = ft_cstring_split(str, "\t\n\v\f\r ");
	result.envp = init_environment(environ);
	if (!result.args || !result.envp)
	{
		pipex_free_node(result);
		return (true);
	}
	*out = result;
	return (false);
}
