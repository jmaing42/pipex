/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

void	ms_builtin_echo(char **args);
void	ms_builtin_cd(const char *const path);
void	ms_builtin_pwd(void);
void	ms_builtin_export(char *env);
void	ms_builtin_unset(char *key);
void	ms_builtin_env(void);
void	ms_builtin_exit(void);
#endif
