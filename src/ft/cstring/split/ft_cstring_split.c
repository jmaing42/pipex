/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 08:58:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring_split.h"

#include <stdlib.h>
#include <stdbool.h>

#include "ft_cstring.h"

char	**ft_cstring_split(const char *str, const char *charset)
{
	const size_t	length = ft_cstring_split_count(str, charset);
	char **const	result = (char **)malloc(sizeof(char *) * (length + 1));
	size_t			index;
	bool			alloc_failed;
	const char		*tmp;

	if (!result)
		return (NULL);
	result[length] = NULL;
	index = 0;
	str = ft_cstring_find_one_of(str, charset, true);
	while (*str)
	{
		tmp = ft_cstring_find_one_of(str, charset, false);
		result[index] = ft_cstring_duplicate_length(str, tmp - str);
		if (!result[index++])
			alloc_failed = true;
		if (!*tmp || alloc_failed)
			break ;
		str = ft_cstring_find_one_of(tmp, charset, true);
	}
	if (!alloc_failed)
		return (result);
	ft_cstring_split_free(result);
	return (NULL);
}
