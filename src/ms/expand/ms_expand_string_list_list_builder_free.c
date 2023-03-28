/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_string_list_list_builder_free.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:38:08 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/28 19:48:22 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"
#include "ms_expand.h"

#include <stdlib.h>

void	ms_expand_string_list_list_builder_free(
	t_ms_expand_string_list_list_builder *self
)
{
	ms_expand_string_list_list_free(&self->list);
	if (self->builder != NULL)
		stringbuilder_free(self->builder);
}
