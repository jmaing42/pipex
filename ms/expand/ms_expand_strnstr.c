/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_strnstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:24:10 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/06 22:56:27 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"
#include "ms_expand.h"

static bool	find_needle(
	const char *haystack,
	const char *needle,
	size_t cur,
	size_t len
)
{
	size_t	i;

	i = 0;
	while (haystack[i] && needle[i])
	{
		if (haystack[i] != needle[i] || i + cur >= len)
			return (false);
		i++;
	}
	return (true);
}

static char	*compare_front(char *haystack, char *needle)
{
	
}

char	*ms_expand_strnstr(const char *haystack, const char *needle, size_t len, t_edge edge)
{
	size_t	n_len;
	size_t	i;

	if (edge == front)
		return (compare_front(haystack, needle));
	else if (edge == back)
		return (compare_back(haystack, needle));
	i = 0;
	n_len = ft_cstring_length(needle);
	if (!n_len)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle)
			if (find_needle(haystack + i, needle, i, len))
				return ((char *)(haystack + i + n_len));
		i++;
	}
	return (NULL);
}
