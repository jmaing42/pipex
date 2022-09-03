/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:28:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:32:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTRING_H
# define FT_CSTRING_H

# include <stddef.h>
# include <limits.h>

# include "ft_types.h"

/**
 * @brief strlen alternative
 *
 * @param str
 * @return size_t cstring length of str
 */
size_t	ft_strlen(const char *str);
size_t	ft_strnlen(const char *str, size_t max_len);

size_t	ft_strlen_until_set(
			const char *str,
			const char *set,
			bool include_null);
size_t	ft_strlen_until_map(
			const char *str,
			const t_byte *map);
size_t	ft_strnlen_until_set(
			const char *str,
			size_t max_len,
			const char *set,
			bool include_null);
size_t	ft_strnlen_until_map(
			const char *str,
			size_t max_len,
			const t_byte *map);

size_t	ft_strchp(const char *str, char ch);
size_t	ft_strrchp(const char *str, char ch);
size_t	ft_strnchp(const char *str, size_t max_len, char ch);
size_t	ft_strnrchp(const char *str, size_t max_len, char ch);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t len);

#endif
