/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:08:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:35:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

# include "ft_types.h"

/**
 * @brief find index of given byte if any
 *
 * @param mem haystack to find in
 * @param size size of mem
 * @param to_find needle to find
 * @param out result
 * @return true if found
 * @return false if not found
 */
bool	ft_memory_find(const void *mem, size_t size, char to_find, size_t *out);

void	ft_memory_zero(void *mem, size_t len);
void	*ft_memory_set(void *mem, int value, size_t len);
void	ft_memory_copy(void *dest, const void *source, size_t size);

void	*ft_memory_allocate(size_t count, size_t size);
void	*ft_memory_duplicate(const void *source, size_t size);

#endif
