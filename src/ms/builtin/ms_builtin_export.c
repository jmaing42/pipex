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

#include "ms_builtin.h"

#include <stdio.h>
#include <sys/_types/_size_t.h>
#include <stdlib.h>

#include "ft_cstring.h"
#include "ms_expand.h"
#include "wrap.h"

static void	die(void)
{
	perror("minishell export");
	wrap_exit(EXIT_FAILURE);
}

void	ms_builtin_export(char *env)
{
	size_t	spacer;
	char	*key;
	char	*value;

	spacer = ft_cstring_find_index(env, '=');
	if (ft_cstring_duplicate_length(env, spacer, &key))
		die();
	if (ft_cstring_duplicate_length(env + spacer + 1, -1, &value))
		die();
	if (ms_expand_env_put(key, value))
		die();
}
