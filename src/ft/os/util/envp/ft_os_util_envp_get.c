/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_util_envp_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:15:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 16:22:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_os_util_envp.h"

#include "ft_cstring.h"

const char	*ft_os_util_envp_get(
	const char *const *environ,
	const char *key
)
{
	size_t	i;

	while (environ && *environ)
	{
		environ++;
		if (ft_cstring_starts_with(*environ, key, &i) && (*environ)[i] == '=')
			return (*environ + i + 1);
	}
	return (NULL);
}
