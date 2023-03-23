/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:50:24 by seonlim           #+#    #+#             */
/*   Updated: 2023/03/23 16:36:15 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"
#include <stdio.h>
void test_and_or_list(t_ms_and_or_list *and_or_list);

void test_word_part_string_list(t_ms_word_part_string_list *wps_list)
{
	t_ms_word_part_string_list_node *wpsl_node;

	wpsl_node = wps_list->head;
	while (wpsl_node)
	{
		printf("%s\n", wpsl_node->value);
		wpsl_node = wpsl_node->next;
	}
}

void test_word_part_list(t_ms_word_part_list *wp_list)
{
	t_ms_word_part_list_node *wpl_node;

	wpl_node = wp_list->head;
	while (wpl_node)
	{
		if (wpl_node->type == MS_WORD_PART_UNQUOTED)
			test_word_part_string_list(wpl_node->value.unquoted);
		else if (wpl_node->type == MS_WORD_PART_SINGLE_QUOTED)
			printf("%s\n", wpl_node->value.single_quoted);
		else
			test_word_part_string_list(wpl_node->value.double_quoted);
	}
}

void test_word(t_ms_word *word)
{
	test_word_part_list(&word->part_list);
}

void test_word_list(t_ms_word_list *word_list)
{
	t_ms_word_list_node *wl_node;

	wl_node = word_list->head;
	while (wl_node)
	{
		test_word(wl_node->word);
		wl_node = wl_node->next;
	}
}

void test_redirection_list(t_ms_redirection_list *rd_list)
{
	t_ms_redirection_list_node *rdl_node;

	rdl_node = rd_list->head;
	while (rdl_node)
	{
		test_word(rdl_node->target);
		rdl_node = rdl_node->next;
	}
}

void test_redirections(t_ms_redirections *redirections)
{
	test_redirection_list(&redirections->in);
	test_redirection_list(&redirections->out);
}

void test_command_compound(t_ms_command_compound *compound)
{
	test_redirections(&compound->redirections);
	test_and_or_list(&compound->and_or_list);
}

void test_command_simple(t_ms_command_simple *simple)
{
	test_redirections(&simple->redirections);
	test_word_list(&simple->word_list);
}

void test_command(t_ms_command *command)
{
	if (command->type == MS_COMMAND_TYPE_SIMPLE)
		test_command_simple(command->value.simple);
	else if (command->type == MS_COMMAND_TYPE_COMPOUND)
		test_command_compound(command->value.compound);
}

void test_pipe_list(t_ms_pipe_list *pipe_list)
{
	t_ms_pipe_list_node *PL_node;

	PL_node = pipe_list->head;
	while (PL_node)
	{
		test_command(&PL_node->command);
		PL_node = PL_node->next;
	}
}

void test_and_or_list(t_ms_and_or_list *and_or_list)
{
	t_ms_and_or_list_node *AOL_node;

	AOL_node = and_or_list->head;
	while (AOL_node)
	{
		test_pipe_list(&AOL_node->pipe_list);
		AOL_node = AOL_node->next;
	}
}

int test_program(t_ms_program *program)
{
	test_and_or_list(&program->and_or_list);
	return (0);
}
