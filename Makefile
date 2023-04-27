# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 20:47:55 by Juyeong Maing     #+#    #+#              #
#    Updated: 2023/04/27 21:11:12 by Juyeong Maing    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

OBJ_DIR = ./obj

CFLAGS = -Ireadline/include -I./ft -I./ft/byte_map -I./ft/cstring -I./ft/cstring/split -I./ft/io -I./ft/memory -I./ft/os/file -I./ft/os/fork -I./ft/os/pipe -I./ft/os/process -I./ft/os/util/envp -I./ft/simple_map -I./ft/stringbuilder -I./ft/to_lines -I./ft/trie -I./ft/types -I./ft/types/char -I./ft/types/convert/strict -I./ft/types/primitive -I./ms -I./ms/builtin -I./ms/execute -I./ms/expand -I./ms/parse -I./ms/repl -I./wrap
LDFLAGS = -Lreadline/lib -lreadline
OBJS = $(OBJ_DIR)/ft/byte_map/ft_byte_map.o $(OBJ_DIR)/ft/cstring/compare/ft_cstring_compare.o $(OBJ_DIR)/ft/cstring/compare/ft_cstring_compare_length.o $(OBJ_DIR)/ft/cstring/duplicate/ft_cstring_duplicate.o $(OBJ_DIR)/ft/cstring/duplicate/ft_cstring_duplicate_length.o $(OBJ_DIR)/ft/cstring/find/ft_cstring_find.o $(OBJ_DIR)/ft/cstring/find/ft_cstring_find_index.o $(OBJ_DIR)/ft/cstring/find/ft_cstring_find_index_reverse.o $(OBJ_DIR)/ft/cstring/find/ft_cstring_find_one_of.o $(OBJ_DIR)/ft/cstring/ft_cstring_concat.o $(OBJ_DIR)/ft/cstring/ft_cstring_contains_char.o $(OBJ_DIR)/ft/cstring/ft_cstring_ends_with_char.o $(OBJ_DIR)/ft/cstring/ft_cstring_equals.o $(OBJ_DIR)/ft/cstring/ft_cstring_starts_with.o $(OBJ_DIR)/ft/cstring/ft_cstring_strlen.o $(OBJ_DIR)/ft/cstring/ft_cstring_strnchp.o $(OBJ_DIR)/ft/cstring/ft_cstring_strnlen.o $(OBJ_DIR)/ft/cstring/length/ft_cstring_length.o $(OBJ_DIR)/ft/cstring/split/ft_cstring_split.o $(OBJ_DIR)/ft/cstring/split/ft_cstring_split_count.o $(OBJ_DIR)/ft/cstring/split/ft_cstring_split_free.o $(OBJ_DIR)/ft/ft_exit.o $(OBJ_DIR)/ft/ft_malloc.o $(OBJ_DIR)/ft/ft_strict_atoi.o $(OBJ_DIR)/ft/io/ft_io_basic.o $(OBJ_DIR)/ft/memory/ft_memory_allocate.o $(OBJ_DIR)/ft/memory/ft_memory_copy.o $(OBJ_DIR)/ft/memory/ft_memory_duplicate.o $(OBJ_DIR)/ft/memory/ft_memory_find.o $(OBJ_DIR)/ft/memory/ft_memory_set.o $(OBJ_DIR)/ft/memory/ft_memory_zero.o $(OBJ_DIR)/ft/os/file/ft_os_file_close.o $(OBJ_DIR)/ft/os/file/ft_os_file_is_executable.o $(OBJ_DIR)/ft/os/file/ft_os_file_open.o $(OBJ_DIR)/ft/os/file/ft_os_file_open2.o $(OBJ_DIR)/ft/os/file/ft_os_file_resolve_executable_path.o $(OBJ_DIR)/ft/os/fork/ft_os_fork.o $(OBJ_DIR)/ft/os/fork/ft_os_fork_multiple.o $(OBJ_DIR)/ft/os/pipe/ft_os_pipe.o $(OBJ_DIR)/ft/os/process/ft_os_process_wait_pids.o $(OBJ_DIR)/ft/os/util/envp/ft_os_util_envp_get.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_dynamic_free.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_dynamic_get.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_dynamic_new.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_dynamic_pop.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_dynamic_set.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_static_free.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_static_get.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_static_new.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_static_pop.o $(OBJ_DIR)/ft/simple_map/ft_simple_map_static_set.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_append.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_append_char.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_append_string.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_free.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_new.o $(OBJ_DIR)/ft/stringbuilder/ft_stringbuilder_to_string.o $(OBJ_DIR)/ft/to_lines/ft_to_lines.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_drain.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_end.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_feed.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_free.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_get_current_line.o $(OBJ_DIR)/ft/to_lines/ft_to_lines_init.o $(OBJ_DIR)/ft/trie/ft_trie_new.o $(OBJ_DIR)/ft/types/char/ft_types_char_alnum.o $(OBJ_DIR)/ft/types/char/ft_types_char_alpha.o $(OBJ_DIR)/ft/types/char/ft_types_char_ascii.o $(OBJ_DIR)/ft/types/char/ft_types_char_blank.o $(OBJ_DIR)/ft/types/char/ft_types_char_cntrl.o $(OBJ_DIR)/ft/types/char/ft_types_char_digit.o $(OBJ_DIR)/ft/types/char/ft_types_char_graph.o $(OBJ_DIR)/ft/types/char/ft_types_char_lower.o $(OBJ_DIR)/ft/types/char/ft_types_char_print.o $(OBJ_DIR)/ft/types/char/ft_types_char_punct.o $(OBJ_DIR)/ft/types/char/ft_types_char_space.o $(OBJ_DIR)/ft/types/char/ft_types_char_upper.o $(OBJ_DIR)/ft/types/char/ft_types_char_xdigit.o $(OBJ_DIR)/ft/types/convert/strict/ft_types_convert_strict_string_to_int.o $(OBJ_DIR)/ft/types/convert/strict/ft_types_convert_strict_string_to_long_double.o $(OBJ_DIR)/ft/types/primitive/ft_types_primitive_const_pointer.o $(OBJ_DIR)/ft/types/primitive/ft_types_primitive_int.o $(OBJ_DIR)/ft/types/primitive/ft_types_primitive_pointer.o $(OBJ_DIR)/ft/types/primitive/ft_types_primitive_size_t.o $(OBJ_DIR)/ms/builtin/ms_builtin_cd.o $(OBJ_DIR)/ms/builtin/ms_builtin_echo.o $(OBJ_DIR)/ms/builtin/ms_builtin_env.o $(OBJ_DIR)/ms/builtin/ms_builtin_exit.o $(OBJ_DIR)/ms/builtin/ms_builtin_export.o $(OBJ_DIR)/ms/builtin/ms_builtin_pwd.o $(OBJ_DIR)/ms/builtin/ms_builtin_unset.o $(OBJ_DIR)/ms/execute/ms_exectue_redirections_out.o $(OBJ_DIR)/ms/execute/ms_execute.o $(OBJ_DIR)/ms/execute/ms_execute_and_or_list.o $(OBJ_DIR)/ms/execute/ms_execute_builtin_check.o $(OBJ_DIR)/ms/execute/ms_execute_builtin_run.o $(OBJ_DIR)/ms/execute/ms_execute_check_infiles.o $(OBJ_DIR)/ms/execute/ms_execute_child.o $(OBJ_DIR)/ms/execute/ms_execute_command.o $(OBJ_DIR)/ms/execute/ms_execute_command_compound.o $(OBJ_DIR)/ms/execute/ms_execute_exit.o $(OBJ_DIR)/ms/execute/ms_execute_globals.o $(OBJ_DIR)/ms/execute/ms_execute_pipe_and_fork.o $(OBJ_DIR)/ms/execute/ms_execute_pipe_list.o $(OBJ_DIR)/ms/execute/ms_execute_program.o $(OBJ_DIR)/ms/execute/ms_execute_redirect_in_out.o $(OBJ_DIR)/ms/execute/ms_execute_redirections_in.o $(OBJ_DIR)/ms/execute/ms_execute_redirections_word_to_str.o $(OBJ_DIR)/ms/execute/ms_execute_set_signals.o $(OBJ_DIR)/ms/execute/ms_execute_simple.o $(OBJ_DIR)/ms/expand/ms_expand.o $(OBJ_DIR)/ms/expand/ms_expand_asterisk.o $(OBJ_DIR)/ms/expand/ms_expand_env_get.o $(OBJ_DIR)/ms/expand/ms_expand_env_get_environ.o $(OBJ_DIR)/ms/expand/ms_expand_env_init.o $(OBJ_DIR)/ms/expand/ms_expand_env_list_get.o $(OBJ_DIR)/ms/expand/ms_expand_env_put.o $(OBJ_DIR)/ms/expand/ms_expand_internal.o $(OBJ_DIR)/ms/expand/ms_expand_string_list_free.o $(OBJ_DIR)/ms/expand/ms_expand_string_list_list_free.o $(OBJ_DIR)/ms/expand/ms_expand_strnstr.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_add_list_list_node.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_add_list_node.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_char.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_string.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_list.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_part_list.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_feed_word_part_list_node.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_fill_node.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_finalize.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_free.o $(OBJ_DIR)/ms/expand/string_list_list_builder/ms_expand_string_list_list_builder_init.o $(OBJ_DIR)/ms/ms_free.o $(OBJ_DIR)/ms/ms_tmpname_find.o $(OBJ_DIR)/ms/ms_tmpname_init.o $(OBJ_DIR)/ms/parse/ms_parse.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command_add_redirection.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command_compound.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command_is_redirection.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command_is_word.o $(OBJ_DIR)/ms/parse/parse/command/ms_parse_parse_command_simple.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_and_or_list.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_command.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_pipe_list.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_program.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_redirections.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_word.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_word_part.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_word_part_list.o $(OBJ_DIR)/ms/parse/parse/free/ms_parse_free_word_part_string_list.o $(OBJ_DIR)/ms/parse/parse/ms_parse_parse_and_or_list.o $(OBJ_DIR)/ms/parse/parse/ms_parse_parse_pipe_list.o $(OBJ_DIR)/ms/parse/parse/ms_parse_parse_program.o $(OBJ_DIR)/ms/parse/parse/ms_parse_parse_util_skip_space_if_any.o $(OBJ_DIR)/ms/parse/parse/word/ms_parse_parse_word.o $(OBJ_DIR)/ms/parse/parse/word/ms_parse_parse_word_part_double_quoted.o $(OBJ_DIR)/ms/parse/parse/word/ms_parse_parse_word_part_fill.o $(OBJ_DIR)/ms/parse/parse/word/ms_parse_parse_word_part_single_quoted.o $(OBJ_DIR)/ms/parse/parse/word/ms_parse_parse_word_part_unquoted.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_add_simple_token.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_add_string_token.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_default.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_double_quote.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_free.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_quote.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_space.o $(OBJ_DIR)/ms/parse/tokenize/ms_parse_tokenize_word.o $(OBJ_DIR)/ms/repl/ms_repl_die.o $(OBJ_DIR)/ms/repl/ms_repl_heredoc_make_tmpfile.o $(OBJ_DIR)/ms/repl/ms_repl_heredoc_parse.o $(OBJ_DIR)/ms/repl/ms_repl_heredoc_signals.o $(OBJ_DIR)/ms/repl/ms_repl_line.o $(OBJ_DIR)/ms/repl/ms_repl_main.o $(OBJ_DIR)/ms/repl/ms_repl_set_signals.o $(OBJ_DIR)/ms/repl/ms_repl_set_terminal.o $(OBJ_DIR)/ms_main.o $(OBJ_DIR)/wrap/wrap_access.o $(OBJ_DIR)/wrap/wrap_close.o $(OBJ_DIR)/wrap/wrap_dup.o $(OBJ_DIR)/wrap/wrap_dup2.o $(OBJ_DIR)/wrap/wrap_exit.o $(OBJ_DIR)/wrap/wrap_fork.o $(OBJ_DIR)/wrap/wrap_free.o $(OBJ_DIR)/wrap/wrap_malloc.o $(OBJ_DIR)/wrap/wrap_open.o $(OBJ_DIR)/wrap/wrap_pipe.o $(OBJ_DIR)/wrap/wrap_read.o $(OBJ_DIR)/wrap/wrap_unlink.o $(OBJ_DIR)/wrap/wrap_wait.o $(OBJ_DIR)/wrap/wrap_waitpid.o $(OBJ_DIR)/wrap/wrap_write.o 

default: all
.PHONY: default


.PHONY: all
all: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: bonus
bonus: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
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
	(printf ".*\n*.o\n\n" && echo "$(NAME)" | xargs -n 1 echo) > $@


$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%$(SUFFIX).o: %.c | prelude
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MJ $@.compile_commands.part.json -MMD -o $@ -c $<

.PHONY: prelude
prelude:
	$(MAKE) -C readline
