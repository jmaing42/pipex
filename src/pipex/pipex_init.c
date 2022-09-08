/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:46:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/09 01:04:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_pipe.h"
#include "pipex.h"

#include <fcntl.h>

#include "wrap.h"
#include "ft_os_file.h"
#include "ft_os_pipe.h"

static t_err	init_self(t_pipex *self, size_t argc, char **argv)
{
	self->node_count = 0;
	self->out = NULL;
	self->in = ft_os_file_open(argv[0], O_RDONLY);
	if (!self->in)
		return (true);
	self->out
		= ft_os_file_open2(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!self->out)
	{
		ft_os_file_close(self->in);
		return (true);
	}
	return (false);
}

static t_err	init_child(t_pipex *self, size_t argc, char **argv)
{
	size_t	i;

	self->node_count = argc - 2;
	i = 0;
	while (++i < argc - 1)
	{
		if (pipex_new_node(&self->node[i - 1], argv[i], i))
		{
			self->node_count = i - 1;
			break ;
		}
	}
	return (self->node_count != argc - 2);
}

t_pipex	*pipex_init(size_t argc, char **argv)
{
	t_pipex	*result;

	if (argc < 3)
		return (NULL);
	result = wrap_malloc(sizeof(t_pipex) + (argc - 2) * sizeof(t_pipex_node));
	if (init_self(result, argc, argv) || init_child(result, argc, argv))
	{
		pipex_free(result);
		return (NULL);
	}
	return (result);
}
