/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_find_index_reverse.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:25:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:29:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#ifdef DEVELOPMENT

# include <stdlib.h>
# include <unistd.h>

# include "ft_io.h"
# include "ft_exit.h"

size_t	ft_cstring_find_index_reverse(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	if (!str)
	{
		ft_puts(
			STDERR_FILENO,
			"ft_cstring_find_index_reverse(): wrong parameter given\n");
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	i = -1;
	result = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#else

size_t	ft_cstring_find_index_reverse(const char *str, char ch)
{
	size_t	result;
	size_t	i;

	i = -1;
	result = -1;
	while (str[++i])
		if (str[i] == ch)
			result = i;
	return (result);
}

#endif
