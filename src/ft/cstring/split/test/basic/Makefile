BASE_PATH := ../../../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/just_run.sh" "ft/cstring/split"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=undefined

include $(BASE_PATH)/build/test.mk
