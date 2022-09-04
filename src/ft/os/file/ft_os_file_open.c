/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file_open.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:15:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:16:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_file.h"

#include "wrap.h"

#include "ft_cstring.h"
#include "ft_memory.h"

t_ft_os_file	*ft_os_file_open(const char *path, int mode)
{
	const int			fd = wrap_open(path, mode);
	const size_t		path_length = ft_cstring_length(path);
	t_ft_os_file *const	result
		= wrap_malloc(sizeof(t_ft_os_file) + path_length + 1);

	if (fd == -1 || !result)
	{
		if (fd == -1)
			wrap_close(fd);
		wrap_free(result);
		return (NULL);
	}
	result->fd = fd;
	result->mode = mode;
	ft_memory_copy(result->path, path, path_length + 1);
	return (result);
}
