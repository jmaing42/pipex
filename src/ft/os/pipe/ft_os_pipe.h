/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_pipe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:37:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 04:37:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_PIPE_H
# define FT_OS_PIPE_H

# include "ft_types.h"

t_err	ft_os_pipe(int *to_read, int *to_write);

#endif