/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:27:24 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/30 21:28:39 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ft_types.h"
#include "ms_expand.h"
#include <sys/_types/_size_t.h>

t_err	ms_expand_env_init(char **envp)
{
	size_t	index;
	size_t	spacer;
	char	*key;
	char	*value;

	index = 0;
	while (envp[index])
	{
		spacer = ft_cstring_find_index(envp[index], '=');
		if (ft_cstring_duplicate_length(envp[index], spacer, &key))
			return (true);
		if (ft_cstring_duplicate_length(envp[index] + spacer + 1, -1, &value))
			return (true);
		if (ms_expand_env_put(key, value))
			return (true);
		index++;
	}
	return (false);
}
