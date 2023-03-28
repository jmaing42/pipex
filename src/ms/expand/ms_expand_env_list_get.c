/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_env_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:29:09 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/28 20:35:47 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

void	*ms_env_list_out(void)
{
	static t_ms_expand_env_list	env_list = {NULL, NULL};

	return (&env_list);
}
