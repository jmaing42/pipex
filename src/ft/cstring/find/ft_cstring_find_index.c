/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_find_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:25:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:29:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#ifdef DEVELOPMENT

# include <stdlib.h>
# include <unistd.h>

# include "ft_io.h"
# include "ft_exit.h"

size_t	ft_cstring_find_index(const char *str, char ch)
{
	size_t	result;

	if (!str)
	{
		ft_puts(
			STDERR_FILENO,
			"ft_cstring_find_index(): wrong parameter given\n");
		ft_exit(EXIT_FAILURE);
		return (0);
	}
	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

#else

size_t	ft_cstring_find_index(const char *str, char ch)
{
	size_t	result;

	result = -1;
	while (str[++result])
		if (str[result] == ch)
			break ;
	return (result);
}

#endif
