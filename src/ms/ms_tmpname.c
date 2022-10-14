/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tmpname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/10/14 20:07:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

#include <stdbool.h>

#include "ft_cstring.h"
#include "wrap.h"

const char *const	g_prefix = "/tmp/pipex_tmp";

t_err	ms_tmpname(char **out)
{
	unsigned int	i;
	unsigned int	tmp;
	char			buffer[5];

	buffer[4] = '\0';
	i = -1;
	while (++i < 9999)
	{
		tmp = i;
		buffer[3] = tmp % 10;
		tmp /= 10;
		buffer[2] = tmp % 10;
		tmp /= 10;
		buffer[1] = tmp % 10;
		tmp /= 10;
		buffer[0] = tmp % 10;
		if (ft_cstring_concat(g_prefix, buffer, out))
			return (true);
		if (wrap_access(*out, F_OK))
			return (false);
		wrap_free(*out);
	}
	return (true);
}
