/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
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
	while (++i < 10000)
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
