/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file_open.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:15:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 06:33:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_file.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_cstring.h"
#include "ft_memory.h"

t_ft_os_file	*ft_os_file_open(char *path, int mode)
{
	const int			fd = open(path, mode);
	const size_t		path_length = ft_cstring_length(path);
	t_ft_os_file *const	result = malloc(sizeof(t_ft_os_file) + path_length + 1);

	if (fd == -1 || !result)
	{
		if (fd == -1)
			close(fd);
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->mode = mode;
	ft_memcpy(result->path, path, path_length + 1);
	return (result);
}
