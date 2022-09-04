/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:40:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 21:06:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "ft_cstring_split.h"
#include "test.h"

int	main(void)
{
	char **const	s1 = ft_cstring_split("Hello, world!\n", ", \n");

	assert_not_null(s1);
	assert_str_eq(s1[0], "Hello");
	assert_str_eq(s1[1], "world!");
	assert_null(s1[2]);
}
