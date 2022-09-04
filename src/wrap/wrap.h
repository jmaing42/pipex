/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:39:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:13:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAP_H
# define WRAP_H

# include <stddef.h>
# include <unistd.h>

void	*wrap_malloc(size_t size);
void	wrap_free(void *memory);
ssize_t	wrap_write(int fd, const void *buffer, size_t bytes);
ssize_t	wrap_read(int fd, void *buffer, size_t bytes);
void	wrap_exit(int status);
int		wrap_open(const char *path, int flags);
int		wrap_open2(const char *path, int flags, int additional_flags);
int		wrap_close(int fd);
int		wrap_pipe(int fds[2]);
pid_t	wrap_fork(void);
pid_t	wrap_wait(int *stat_loc);
pid_t	wrap_waitpid(pid_t pid, int *stat_loc, int options);
int		wrap_access(const char *pathname, int mode);

#endif
