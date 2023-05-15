/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_finalize        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:12:46 by seonlim           #+#    #+#             */
/*   Updated: 2023/05/15 15:36:33 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ms_expand.h"

t_err	ms_expand_string_list_list_builder_finalize(
	t_ms_expand_string_list_list_builder *self,
	t_ms_expand_string_list_list *out
)
{
	if (self == NULL)
		return (true);
	*out = self->list;
	return (false);
}
