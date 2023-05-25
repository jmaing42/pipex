/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
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
		ft_stringbuilder_free(self->builder);
}
