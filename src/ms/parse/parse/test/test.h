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

#ifndef TEST_H
# define TEST_H

# include "ms.h"

t_err	print_program(t_ms_program *program);

t_err	print_and_or_list(int depth, t_ms_and_or_list *and_or_list);
t_err	print_pipe_list(int depth, t_ms_pipe_list *pipe_list);
t_err	print_command(int depth, t_ms_command *command);
t_err	print_redirections(int depth, t_ms_redirections *redirections);
t_err	print_word_list(int depth, t_ms_word_list *word_list);
t_err	print_word(int depth, t_ms_word *word);

#endif
