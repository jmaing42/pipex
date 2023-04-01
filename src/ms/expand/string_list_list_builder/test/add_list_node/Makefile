BASE_PATH := ../../../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/just_run.sh" "ms/expand/string_list_list_builder/add_list_node"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/leak_test.mk
