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

#include "ft_io.h"
#include "ft_memory.h"
#include "ms_builtin.h"

#include <stdio.h>
#include <sys/_types/_size_t.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring.h"
#include "ms_execute.h"
#include "ms_expand.h"
#include "wrap.h"

static bool	is_registerd(char *key)
{
	t_ms_expand_env_list *const	list = ms_expand_env_list_get();
	t_ms_expand_env_list_node	*node;

	node = list->head;
	while (node)
	{
		if (ft_cstring_equals(node->key, key))
			return (true);
		node = node->next;
	}
	return (false);
}

static t_err	get_key_and_value(char *env, char **out_key, char **out_value)
{
	size_t	spacer;

	spacer = ft_cstring_find_index(env, '=');
	if (ft_cstring_duplicate_length(env, spacer, out_key))
		return (true);
	if (env[spacer] == '\0')
		return (false);
	if (ft_cstring_duplicate_length(env + spacer + 1, -1, out_value))
	{
		wrap_free(*out_key);
		return (true);
	}
	return (false);
}

static t_err	call_unset(char *key)
{
	char	**args;

	args = ft_memory_allocate(3, sizeof(char *));
	if (args == NULL)
		return (true);
	args[1] = key;
	ms_builtin_unset(args);
	wrap_free(args);
	return (false);
}

static t_err	register_env(char *env)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (ft_cstring_equals(env, ""))
	{
		ft_puts(STDERR_FILENO, "minishell export: not valid in this context\n");
		return (false);
	}
	if (get_key_and_value(env, &key, &value))
		return (true);
	if (key == NULL || value == NULL)
		return (false);
	if (is_registerd(key))
		if (call_unset(key))
			return (true);
	if (ms_expand_env_put(key, value))
		return (true);
	return (false);
}
// TODO: export A=a "" B=b

void	ms_builtin_export(char **args)
{
	size_t	index;

	ms_execute_globals()->exit_status = EXIT_SUCCESS;
	index = 1;
	while (args[index])
	{
		if (register_env(args[index]))
		{
			perror("minishell export");
			ms_execute_globals()->exit_status = EXIT_FAILURE;
			return ;
		}
		++index;
	}
}
