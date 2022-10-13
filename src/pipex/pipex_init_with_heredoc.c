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

#include "pipex.h"

#include <fcntl.h>

#include "wrap.h"
#include "ft_os_file.h"
#include "ft_os_pipe.h"

t_pipex	*pipex_init_with_heredoc(size_t argc, char **argv)
{
	t_pipex	*result;

	if (argc < 4)
		return (NULL);
	(void)result;
	(void)argv;
	return (NULL);
}
