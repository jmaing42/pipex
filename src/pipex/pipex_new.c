/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:46:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 20:05:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <fcntl.h>
#include <sys/fcntl.h>

#include "wrap.h"
#include "ft_os_file.h"

t_pipex	*pipex_new(size_t argc, char **argv)
{
	t_pipex	*result;
	size_t	i;

	if (argc < 3)
		return (NULL);
	result = wrap_malloc(sizeof(t_pipex) + (argc - 2) * sizeof(t_pipex_node));
	result->node_count = argc - 2;
	result->in = ft_os_file_open(argv[0], O_RDONLY);
	result->out = ft_os_file_open2(
			argv[argc - 1], O_WRONLY | O_CREAT | O_EXCL, 0644);
	i = 0;
	while (++i < argc - 1)
	{
		if (pipex_new_node(&result->node[i - 1], argv[i]))
		{
			result->node_count = i - 1;
			break ;
		}
	}
	if (result->node_count != argc - 2)
	{
		pipex_free(result);
		return (NULL);
	}
	return (result);
}
