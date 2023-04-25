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

#include "ft_cstring.h"
#include "ft_types.h"
#include "wrap.h"

static const char *const	g_prefix = "/tmp/minishell_tmp";

static void	fill_buffer(char *out_buffer, unsigned int i)
{
	unsigned int	tmp;

	tmp = i;
	out_buffer[3] = (tmp % 10) + '0';
	tmp /= 10;
	out_buffer[2] = (tmp % 10) + '0';
	tmp /= 10;
	out_buffer[1] = (tmp % 10) + '0';
	tmp /= 10;
	out_buffer[0] = (tmp % 10) + '0';
}

t_err	ms_tmpname_init(void)
{
	unsigned int	i;
	char			buffer[5];
	char			*path;

	buffer[4] = '\0';
	i = -1;
	while (++i < 10000)
	{
		fill_buffer(buffer, i);
		if (ft_cstring_concat(g_prefix, buffer, &path))
			return (true);
		if (wrap_access(path, F_OK) != FILE_EXIST)
		{
			wrap_free(path);
			return (false);
		}
		wrap_unlink(path);
		wrap_free(path);
	}
	return (false);
}
