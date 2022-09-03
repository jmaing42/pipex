/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_split_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:37:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 05:23:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <stdlib.h>

void	ft_cstring_split_free(char	**null_terminated_strings)
{
	char	**tmp;

	tmp = null_terminated_strings;
	while (*tmp)
		free(*tmp++);
	free(null_terminated_strings);
}
