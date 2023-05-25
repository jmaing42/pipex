/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_strnstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:24:10 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/07 15:46:03 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ms_expand.h"
#include <stdio.h>

static bool	find_needle(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (haystack[i] && needle[i])
	{
		if (haystack[i] != needle[i])
			return (false);
		i++;
	}
	return (true);
}

static char	*front_strnstr(const char *haystack, const char *needle)
{
	const size_t	needle_len = ft_cstring_length(needle);
	size_t			index;

	index = 0;
	while (index < needle_len)
	{
		if (haystack[index] != needle[index])
			return (NULL);
		++index;
	}
	return ((char *)haystack + index);
}

static char	*back_strnstr(const char *haystack, const char *needle)
{
	const size_t	needle_len = ft_cstring_length(needle);
	const size_t	haystack_len = ft_cstring_length(haystack);
	size_t			index;

	index = 0;
	while (index <= needle_len)
	{
		if (haystack[haystack_len - index] != needle[needle_len - index])
			return (NULL);
		++index;
	}
	return ((char *)haystack + (haystack_len - index));
}

char	*ms_expand_strnstr(
	const char *haystack,
	const char *needle,
	t_position pos)
{
	size_t	n_len;
	size_t	i;

	if (pos == front)
		return (front_strnstr(haystack, needle));
	else if (pos == back)
		return (back_strnstr(haystack, needle));
	i = 0;
	n_len = ft_cstring_length(needle);
	if (!n_len)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == *needle)
			if (find_needle(haystack + i, needle))
				return ((char *)(haystack + i + n_len));
		i++;
	}
	return (NULL);
}
