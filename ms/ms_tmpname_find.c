/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tmpname_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/04/22 15:08:04 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

#include <stdbool.h>

#include "ft_cstring.h"
#include "wrap.h"

static const char *const	g_prefix = "/tmp/minishell_tmp";

t_err	ms_tmpname_find(char **out)
{
	unsigned int	i;
	unsigned int	tmp;
	char			buffer[5];

	buffer[4] = '\0';
	i = -1;
	while (++i < 10000)
	{
		tmp = i;
		buffer[3] = (tmp % 10) + '0';
		tmp /= 10;
		buffer[2] = (tmp % 10) + '0';
		tmp /= 10;
		buffer[1] = (tmp % 10) + '0';
		tmp /= 10;
		buffer[0] = (tmp % 10) + '0';
		if (ft_cstring_concat(g_prefix, buffer, out))
			return (true);
		if (wrap_access(*out, F_OK) != FILE_EXIST)
			return (false);
		wrap_free(*out);
	}
	return (true);
}
