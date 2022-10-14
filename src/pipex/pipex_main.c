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

#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring.h"
#include "ft_cstring_split.h"
#include "ft_io.h"
#include "ft_os_fork.h"
#include "ft_os_process.h"
#include "ft_os_util_envp.h"

#include "ft_malloc.h"

static bool	is_heredoc(int argc, char **argv)
{
	return (argc >= 2 && ft_cstring_equals(argv[1], "here_doc"));
}

int	pipex_main(int argc, char **argv)
{
	// TODO
}
