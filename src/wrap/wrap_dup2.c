/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:39:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 07:39:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrap.h"

#include <unistd.h>

int	wrap_dup2(int source_fd, int new_fd)
{
	return (dup2(source_fd, new_fd));
}
