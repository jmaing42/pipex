/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_util_skip_space_if_any.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2022/12/17 16:45:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"

void	ms_parse_parse_util_skip_space_if_any(
	t_ms_parse_token_list_node **head
)
{
	if ((*head)->value.type == MS_PARSE_TOKEN_TYPE_SPACE)
		*head = (*head)->next;
}
