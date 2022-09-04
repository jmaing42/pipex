/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 12:07:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_types_convert_strict.h"

int	main(int argc, char **argv)
{
	char	buffer[1024];
	int		i;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	while (true)
	{
		if (scanf(" %1000[^\n]", buffer) != 1)
			break ;
		if (ft_types_convert_strict_string_to_int(buffer, &i))
			puts("invalid");
		else
			printf("%d\n", i);
	}
	if (!feof(stdin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
