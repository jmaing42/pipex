/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_fd_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:29:23 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/08 17:33:47 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdlib.h>

#include "wrap.h"
#include "ft_io.h"

void	ms_execute_fd_exit(int fd, char *message)
{
	if (ft_puts(fd, message))
		wrap_exit(EXIT_FAILURE);
	wrap_exit(EXIT_FAILURE);
}
