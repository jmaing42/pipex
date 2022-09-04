/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_file_resolve_executable_path.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:56:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:47:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include "wrap.h"
#include "ft_os_file.h"

static char	*to_full_path(const char *path, const char *name)
{
	char	*tmp;
	char	*temp;

	if (ft_cstring_ends_with_char(path, '/'))
		return (ft_cstring_concat(path, name));
	temp = ft_cstring_concat(path, "/");
	if (!temp)
		return (NULL);
	tmp = ft_cstring_concat(temp, name);
	wrap_free(temp);
	return (tmp);
}

t_err	ft_os_file_resolve_executable_path(
	const char *name,
	const char *const *path,
	char **out
)
{
	const char *const	*tmp;
	char				*full_path;

	*out = NULL;
	tmp = path - 1;
	while (*++tmp)
	{
		full_path = to_full_path(*tmp, name);
		if (!full_path)
			return (true);
		if (ft_os_file_is_executable(full_path))
		{
			*out = full_path;
			return (false);
		}
		wrap_free(full_path);
	}
	return (false);
}
