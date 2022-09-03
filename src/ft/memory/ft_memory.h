/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:08:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:32:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

# include "ft_types.h"

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *mem, size_t len);
void	*ft_memset(void *mem, int value, size_t len);
void	ft_memcpy(void *dest, const void *source, size_t size);
void	*ft_memdup(const void *source, size_t size);

bool	ft_memory_find(const void *mem, size_t size, char to_find, size_t *out);

#endif
