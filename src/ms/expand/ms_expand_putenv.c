/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_putenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:05:37 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/28 20:36:25 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_expand.h"

#include <stdlib.h>

t_err	ms_expand_putenv(const char *key, const char *value)
{
	static t_ms_expand_env_list	env_list = {NULL, NULL};

	
}
