/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file_is_executable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:17:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:18:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_file.h"

#include <unistd.h>

#include "wrap.h"

bool	ft_os_file_is_executable(const char *path)
{
	return (wrap_access(path, X_OK) == 0);
}
