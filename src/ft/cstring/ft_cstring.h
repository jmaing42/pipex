/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:28:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/07 00:21:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTRING_H
# define FT_CSTRING_H

# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

# include "ft_types.h"

/**
 * @brief strlen alternative
 *
 * @param str
 * @return size_t cstring length of str
 */
size_t		ft_cstring_length(
				const char *str);
size_t		ft_string_length_for(
				const char *str,
				size_t max_len);

size_t		ft_strlen_until_set(
				const char *str,
				const char *set,
				bool include_null);
size_t		ft_strlen_until_map(
				const char *str,
				const t_byte *map);
size_t		ft_strnlen_until_set(
				const char *str,
				size_t max_len,
				const char *set,
				bool include_null);
size_t		ft_strnlen_until_map(
				const char *str,
				size_t max_len,
				const t_byte *map);

size_t		ft_strnchp(
				const char *str,
				size_t max_len,
				char ch);
size_t		ft_strnrchp(
				const char *str,
				size_t max_len,
				char ch);

int			ft_cstring_compare(
				const char *a,
				const char *b);
int			ft_cstring_compare_length(
				const char *a,
				const char *b,
				size_t length);

t_err		ft_cstring_duplicate(
				const char *src,
				char **out);
t_err		ft_cstring_duplicate_length(
				const char *src,
				size_t max_len,
				char **out);
t_err		ft_cstring_concat(
				const char *a,
				const char *b,
				char **out);

const char	*ft_cstring_find(
				const char *str,
				char c);
const char	*ft_cstring_find_one_of(
				const char *str,
				const char *charset,
				bool negate);
size_t		ft_cstring_find_index(
				const char *str,
				char ch);
size_t		ft_cstring_find_index_reverse(
				const char *str,
				char ch);

bool		ft_cstring_equals(
				const char *a,
				const char *b);
bool		ft_cstring_starts_with(
				const char *self,
				const char *substring,
				size_t *substring_length);
bool		ft_cstring_ends_with_char(
				const char *self,
				char expected_end);
bool		ft_cstring_contains_char(
				const char *self,
				char expected);

#endif
