/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:17:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/28 23:26:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fto_stream_fd_in.h"

#define BUFFER_SIZE 4

int	main(void)
{
	t_fto_stream_in *const	stream
		= (t_fto_stream_in *)new_fto_stream_fd_in(STDIN_FILENO, true);
	char					buffer[BUFFER_SIZE];
	size_t					bytes_read;

	if (!stream)
		return (EXIT_FAILURE);
	while (
		!stream->v->end(stream)
		&& !stream->v->read(stream, buffer, BUFFER_SIZE, &bytes_read)
	)
		fwrite(buffer, 1, bytes_read, stdout);
	if (!stream->v->end(stream))
		return (true);
	return (EXIT_SUCCESS);
}
