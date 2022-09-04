/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:34:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:38:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_FILE_H
# define FT_OS_FILE_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_ft_os_file
{
	int		fd;
	int		mode;
	char	path[];
}	t_ft_os_file;

t_ft_os_file	*ft_os_file_open(const char *path, int mode);
t_ft_os_file	*ft_os_file_open2(const char *path, int mode, int permission);
void			ft_os_file_close(t_ft_os_file *file);

bool			ft_os_file_is_executable(const char *path);

t_err			ft_os_file_resolve_executable_path(
					const char *name,
					const char *const *path,
					char **out);

#endif
