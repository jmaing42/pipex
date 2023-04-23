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
# define GET_EOF NULL
# define EXIT_BY_SIGNAL 127

# include "ms.h"
# include "ft_types.h"
# include <sys/_types/_pid_t.h>

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
void	ms_repl_set_signals(void);
void	ms_repl_line(void);
t_err	ms_repl_heredoc_parse(
			t_ms_program *mut,
			t_ms_repl_string_list *out_tmp_files);
void	ms_repl_clear_tmp_files(
			t_ms_repl_string_list *list);
void	ms_repl_string_list_free(
			t_ms_repl_string_list *list);
t_err	ms_repl_set_termianl(void);
t_err	ms_repl_heredoc_make_tmpfile(
			t_ms_redirection_list_node *node,
			char *file_name,
			char *limiter);
void	ms_repl_heredoc_signals(pid_t is_child);
int		*ms_repl_heredoc_globals(void);
#endif
