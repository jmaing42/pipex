/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:42:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 01:43:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_file.h"

#include <stdlib.h>
#include <unistd.h>

void	ft_os_file_close(t_ft_os_file *file)
{
	close(file->fd);
	free(file);
}
