/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_split.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 05:27:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 05:34:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTRING_SPLIT_H
# define FT_CSTRING_SPLIT_H

# include <stddef.h>

char	*ft_cstring_duplicate(const char *str, const char *charset);
size_t	ft_cstring_split_count(const char *str, const char *charset);
void	ft_cstring_split_free(char	**null_terminated_strings);

#endif
