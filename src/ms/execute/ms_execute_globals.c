/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:20 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/20 22:40:55 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

t_ms_execute_globals	*ms_execute_globals(void)
{
	static t_ms_execute_globals	globals = {
		0,
	};

	return (&globals);
}
