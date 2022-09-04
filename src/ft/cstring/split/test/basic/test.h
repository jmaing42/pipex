/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:49:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 21:01:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdbool.h>

void	assert(bool must_be_true, const char *message);
void	assert_str_eq(char *lhs, char *rhs);
void	assert_null(void *must_be_null);
void	assert_not_null(void *must_not_be_null);

#endif
