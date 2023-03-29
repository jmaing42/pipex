/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_env_list_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:29:09 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/29 15:34:16 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

void	*ms_expand_env_list_get(void)
{
	static t_ms_expand_env_list	env_list = {NULL, NULL};

	return (&env_list);
}
