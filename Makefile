# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 20:47:55 by Juyeong Maing     #+#    #+#              #
#    Updated: 2023/04/29 17:02:20 by Juyeong Maing    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -O -Ireadline/include -I./ft -I./ft/byte_map -I./ft/cstring -I./ft/cstring/split -I./ft/io -I./ft/memory -I./ft/os/file -I./ft/os/fork -I./ft/os/pipe -I./ft/os/process -I./ft/os/util/envp -I./ft/simple_map -I./ft/stringbuilder -I./ft/to_lines -I./ft/trie -I./ft/types -I./ft/types/char -I./ft/types/convert/strict -I./ft/types/primitive -I./ms -I./ms/builtin -I./ms/execute -I./ms/expand -I./ms/parse -I./ms/repl -I./wrap
LDFLAGS = -Lreadline/lib -lreadline
OBJS = ./obj/ft/byte_map/ft_byte_map.o ./obj/ft/cstring/compare/ft_cstring_compare.o ./obj/ft/cstring/compare/ft_cstring_compare_length.o ./obj/ft/cstring/duplicate/ft_cstring_duplicate.o ./obj/ft/cstring/duplicate/ft_cstring_duplicate_length.o ./obj/ft/cstring/find/ft_cstring_find.o ./obj/ft/cstring/find/ft_cstring_find_index.o ./obj/ft/cstring/find/ft_cstring_find_index_reverse.o ./obj/ft/cstring/find/ft_cstring_find_one_of.o ./obj/ft/cstring/ft_cstring_concat.o ./obj/ft/cstring/ft_cstring_contains_char.o ./obj/ft/cstring/ft_cstring_ends_with_char.o ./obj/ft/cstring/ft_cstring_equals.o ./obj/ft/cstring/ft_cstring_starts_with.o ./obj/ft/cstring/ft_cstring_strlen.o ./obj/ft/cstring/ft_cstring_strnchp.o ./obj/ft/cstring/ft_cstring_strnlen.o ./obj/ft/cstring/length/ft_cstring_length.o ./obj/ft/cstring/split/ft_cstring_split.o ./obj/ft/cstring/split/ft_cstring_split_count.o ./obj/ft/cstring/split/ft_cstring_split_free.o ./obj/ft/ft_exit.o ./obj/ft/ft_malloc.o ./obj/ft/ft_strict_atoi.o ./obj/ft/io/ft_io_basic.o ./obj/ft/memory/ft_memory_allocate.o ./obj/ft/memory/ft_memory_copy.o ./obj/ft/memory/ft_memory_duplicate.o ./obj/ft/memory/ft_memory_find.o ./obj/ft/memory/ft_memory_set.o ./obj/ft/memory/ft_memory_zero.o ./obj/ft/os/file/ft_os_file_close.o ./obj/ft/os/file/ft_os_file_is_executable.o ./obj/ft/os/file/ft_os_file_open.o ./obj/ft/os/file/ft_os_file_open2.o ./obj/ft/os/file/ft_os_file_resolve_executable_path.o ./obj/ft/os/fork/ft_os_fork.o ./obj/ft/os/fork/ft_os_fork_multiple.o ./obj/ft/os/pipe/ft_os_pipe.o ./obj/ft/os/process/ft_os_process_wait_pids.o ./obj/ft/os/util/envp/ft_os_util_envp_get.o ./obj/ft/simple_map/ft_simple_map_dynamic_free.o ./obj/ft/simple_map/ft_simple_map_dynamic_get.o ./obj/ft/simple_map/ft_simple_map_dynamic_new.o ./obj/ft/simple_map/ft_simple_map_dynamic_pop.o ./obj/ft/simple_map/ft_simple_map_dynamic_set.o ./obj/ft/simple_map/ft_simple_map_static_free.o ./obj/ft/simple_map/ft_simple_map_static_get.o ./obj/ft/simple_map/ft_simple_map_static_new.o ./obj/ft/simple_map/ft_simple_map_static_pop.o ./obj/ft/simple_map/ft_simple_map_static_set.o ./obj/ft/stringbuilder/ft_stringbuilder_append.o ./obj/ft/stringbuilder/ft_stringbuilder_append_char.o ./obj/ft/stringbuilder/ft_stringbuilder_append_string.o ./obj/ft/stringbuilder/ft_stringbuilder_free.o ./obj/ft/stringbuilder/ft_stringbuilder_new.o ./obj/ft/stringbuilder/ft_stringbuilder_to_string.o ./obj/ft/to_lines/ft_to_lines.o ./obj/ft/to_lines/ft_to_lines_drain.o ./obj/ft/to_lines/ft_to_lines_end.o ./obj/ft/to_lines/ft_to_lines_feed.o ./obj/ft/to_lines/ft_to_lines_free.o ./obj/ft/to_lines/ft_to_lines_get_current_line.o ./obj/ft/to_lines/ft_to_lines_init.o ./obj/ft/trie/ft_trie_new.o ./obj/ft/types/char/ft_types_char_alnum.o ./obj/ft/types/char/ft_types_char_alpha.o ./obj/ft/types/char/ft_types_char_ascii.o ./obj/ft/types/char/ft_types_char_blank.o ./obj/ft/types/char/ft_types_char_cntrl.o ./obj/ft/types/char/ft_types_char_digit.o ./obj/ft/types/char/ft_types_char_graph.o ./obj/ft/types/char/ft_types_char_lower.o ./obj/ft/types/char/ft_types_char_print.o ./obj/ft/types/char/ft_types_char_punct.o ./obj/ft/types/char/ft_types_char_space.o ./obj/ft/types/char/ft_types_char_upper.o ./obj/ft/types/char/ft_types_char_xdigit.o ./obj/ft/types/convert/strict/ft_types_convert_strict_string_to_int.o ./obj/ft/types/convert/strict/ft_types_convert_strict_string_to_long_double.o ./obj/ft/types/primitive/ft_types_primitive_const_pointer.o ./obj/ft/types/primitive/ft_types_primitive_int.o ./obj/ft/types/primitive/ft_types_primitive_pointer.o ./obj/ft/types/primitive/ft_types_primitive_size_t.o ./obj/ms/builtin/ms_builtin_cd.o ./obj/ms/builtin/ms_builtin_echo.o ./obj/ms/builtin/ms_builtin_env.o ./obj/ms/builtin/ms_builtin_exit.o ./obj/ms/builtin/ms_builtin_export.o ./obj/ms/builtin/ms_builtin_pwd.o ./obj/ms/builtin/ms_builtin_unset.o ./obj/ms/execute/ms_exectue_redirections_out.o ./obj/ms/execute/ms_execute.o ./obj/ms/execute/ms_execute_and_or_list.o ./obj/ms/execute/ms_execute_builtin_check.o ./obj/ms/execute/ms_execute_builtin_run.o ./obj/ms/execute/ms_execute_check_infiles.o ./obj/ms/execute/ms_execute_child.o ./obj/ms/execute/ms_execute_command.o ./obj/ms/execute/ms_execute_command_compound.o ./obj/ms/execute/ms_execute_exit.o ./obj/ms/execute/ms_execute_globals.o ./obj/ms/execute/ms_execute_pipe_and_fork.o ./obj/ms/execute/ms_execute_pipe_list.o ./obj/ms/execute/ms_execute_program.o ./obj/ms/execute/ms_execute_redirect_in_out.o ./obj/ms/execute/ms_execute_redirections_in.o ./obj/ms/execute/ms_execute_redirections_word_to_str.o ./obj/ms/execute/ms_execute_set_signals.o ./obj/ms/execute/ms_execute_simple.o ./obj/ms/expand/ms_expand.o ./obj/ms/expand/ms_expand_asterisk.o ./obj/ms/expand/ms_expand_env_get.o ./obj/ms/expand/ms_expand_env_get_environ.o ./obj/ms/expand/ms_expand_env_init.o ./obj/ms/expand/ms_expand_env_list_get.o ./obj/ms/expand/ms_expand_env_put.o ./obj/ms/expand/ms_expand_internal.o ./obj/ms/expand/ms_expand_string_list_free.o ./obj/ms/expand/ms_expand_string_list_list_free.o ./obj/ms/expand/ms_expand_strnstr.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_add_list_list_node.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_add_list_node.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_char.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_string.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_list.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_part_list.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_part_list_node.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_fill_node.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_finalize.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_free.o ./obj/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_init.o ./obj/ms/ms_free.o ./obj/ms/ms_tmpname_find.o ./obj/ms/ms_tmpname_init.o ./obj/ms/parse/ms_parse.o ./obj/ms/parse/parse/command/ms_parse_parse_command.o ./obj/ms/parse/parse/command/ms_parse_parse_command_add_redirection.o ./obj/ms/parse/parse/command/ms_parse_parse_command_compound.o ./obj/ms/parse/parse/command/ms_parse_parse_command_is_redirection.o ./obj/ms/parse/parse/command/ms_parse_parse_command_is_word.o ./obj/ms/parse/parse/command/ms_parse_parse_command_simple.o ./obj/ms/parse/parse/free/ms_parse_free_and_or_list.o ./obj/ms/parse/parse/free/ms_parse_free_command.o ./obj/ms/parse/parse/free/ms_parse_free_pipe_list.o ./obj/ms/parse/parse/free/ms_parse_free_program.o ./obj/ms/parse/parse/free/ms_parse_free_redirections.o ./obj/ms/parse/parse/free/ms_parse_free_word.o ./obj/ms/parse/parse/free/ms_parse_free_word_part.o ./obj/ms/parse/parse/free/ms_parse_free_word_part_list.o ./obj/ms/parse/parse/free/ms_parse_free_word_part_string_list.o ./obj/ms/parse/parse/ms_parse_parse_and_or_list.o ./obj/ms/parse/parse/ms_parse_parse_pipe_list.o ./obj/ms/parse/parse/ms_parse_parse_program.o ./obj/ms/parse/parse/ms_parse_parse_util_skip_space_if_any.o ./obj/ms/parse/parse/word/ms_parse_parse_word.o ./obj/ms/parse/parse/word/ms_parse_parse_word_part_double_quoted.o ./obj/ms/parse/parse/word/ms_parse_parse_word_part_fill.o ./obj/ms/parse/parse/word/ms_parse_parse_word_part_single_quoted.o ./obj/ms/parse/parse/word/ms_parse_parse_word_part_unquoted.o ./obj/ms/parse/tokenize/ms_parse_tokenize.o ./obj/ms/parse/tokenize/ms_parse_tokenize_add_simple_token.o ./obj/ms/parse/tokenize/ms_parse_tokenize_add_string_token.o ./obj/ms/parse/tokenize/ms_parse_tokenize_default.o ./obj/ms/parse/tokenize/ms_parse_tokenize_double_quote.o ./obj/ms/parse/tokenize/ms_parse_tokenize_free.o ./obj/ms/parse/tokenize/ms_parse_tokenize_quote.o ./obj/ms/parse/tokenize/ms_parse_tokenize_space.o ./obj/ms/parse/tokenize/ms_parse_tokenize_word.o ./obj/ms/repl/ms_repl_die.o ./obj/ms/repl/ms_repl_heredoc_make_tmpfile.o ./obj/ms/repl/ms_repl_heredoc_parse.o ./obj/ms/repl/ms_repl_heredoc_signals.o ./obj/ms/repl/ms_repl_line.o ./obj/ms/repl/ms_repl_main.o ./obj/ms/repl/ms_repl_set_signals.o ./obj/ms/repl/ms_repl_set_terminal.o ./obj/ms_main.o ./obj/wrap/wrap_access.o ./obj/wrap/wrap_close.o ./obj/wrap/wrap_dup.o ./obj/wrap/wrap_dup2.o ./obj/wrap/wrap_exit.o ./obj/wrap/wrap_fork.o ./obj/wrap/wrap_free.o ./obj/wrap/wrap_malloc.o ./obj/wrap/wrap_open.o ./obj/wrap/wrap_pipe.o ./obj/wrap/wrap_read.o ./obj/wrap/wrap_unlink.o ./obj/wrap/wrap_wait.o ./obj/wrap/wrap_waitpid.o ./obj/wrap/wrap_write.o

default: all
.PHONY: default


.PHONY: all
all: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: bonus
bonus: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: clean
clean:
	rm -rf ./obj .editorconfig .gitignore
	$(MAKE) -C readline clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C readline fclean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig

.gitignore:
	(printf ".*\n/obj\n\n" && echo "$(NAME)" | xargs -n 1 echo) > $@


$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

./obj/%$(SUFFIX).o: %.c | prelude
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: prelude
prelude:
	$(MAKE) -C readline
