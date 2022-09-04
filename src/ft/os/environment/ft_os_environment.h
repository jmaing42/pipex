/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_environment.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:08:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 15:21:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OS_ENVIRONMENT_H
# define FT_OS_ENVIRONMENT_H

# include "ft_types.h"
# include "ft_simple_map.h"

extern char	**environ;

typedef struct s_ft_os_environment_builder
{
	t_ft_simple_map_static	*map;
}	t_ft_os_environment_builder;

t_ft_os_environment_builder	*new_ft_os_environment_builder(
								char **environ);
t_ft_os_environment_builder	*ft_os_environment_builder_clone(
								t_ft_os_environment_builder *builder);

char						**ft_os_environment_builder_free(
								t_ft_os_environment_builder *self);

t_err						ft_os_environment_builder_override(
								t_ft_os_environment_builder *self,
								char **environ);
t_err						ft_os_environment_builder_override_entry(
								t_ft_os_environment_builder *self,
								char *key,
								char *value);
t_err						ft_os_environment_builder_override_builder(
								t_ft_os_environment_builder *self,
								t_ft_os_environment_builder *builder);

char						**ft_os_environment_builder_build(
								t_ft_os_environment_builder *self);

#endif
