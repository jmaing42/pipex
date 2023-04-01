BASE_PATH := ../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/inout_filename_env.sh" "ms/expand"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/leak_test.mk
