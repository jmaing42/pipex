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

#ifndef MS_REPL_H
# define MS_REPL_H

# include "ms.h"

# include "ft_types.h"

typedef struct s_ms_repl_string_list_node
{
	struct s_ms_repl_string_list_node	*next;
	char								*str;
}	t_ms_repl_string_list_node;

typedef struct s_ms_repl_string_list
{
	t_ms_repl_string_list_node	*head;
	t_ms_repl_string_list_node	*tail;
}	t_ms_repl_string_list;

void	ms_repl_main(void);

void	ms_repl_die(void);
void	ms_repl_die_if(t_err error);
void	ms_repl_install_signal_handlers(void);
void	ms_repl_line(void);
t_err	ms_repl_replace_heredoc(
			t_ms_program *mut,
			t_ms_repl_string_list **out_tmp_files);
void	ms_repl_clear_tmp_files(t_ms_repl_string_list *list);
void	ms_repl_string_list_free(t_ms_repl_string_list *list);

#endif
