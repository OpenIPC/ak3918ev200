# SPDX-License-Identifier: MIT

CC      ?= gcc
AR      ?= ar
CFLAGS  ?= -O2 -g -Wall -Wextra -std=c11
CPPFLAGS?= -Iinclude -D_GNU_SOURCE
LDFLAGS ?=
LDLIBS  ?=

BUILD_DIR := build
BIN_DIR   := $(BUILD_DIR)/bin
LIBAK     := $(BUILD_DIR)/libak3918.a

LIBAK_SRCS := \
    src/lib/util/util.c \
    src/lib/util/blob.c \
    src/lib/isp/parse_conf.c \
    src/lib/isp/isp_blocks.c \
    src/lib/isp/isp_device.c \
    src/lib/isp/akispsdk_shim.c \
    src/lib/sys/ion.c \
    src/lib/sys/gpio.c \
    src/lib/sys/motor.c \
    src/lib/sys/spiflash.c \
    src/lib/audio/akpcm_device.c \
    src/lib/video/uio.c

LIBAK_OBJS := $(LIBAK_SRCS:%.c=$(BUILD_DIR)/%.o)

VIDEO_DUMP_BIN     := $(BIN_DIR)/ak3918_video_dump
AUDIO_PLAY_BIN     := $(BIN_DIR)/ak3918_audio_play
AUDIO_CAPTURE_BIN  := $(BIN_DIR)/ak3918_audio_capture
ISP_DUMP_BIN       := $(BIN_DIR)/ak3918_dump_isp_conf
TESTING_BIN        := $(BIN_DIR)/ak3918_testing
MOTOR_TEST_BIN     := $(BIN_DIR)/ak3918_motor_test
SPIFLASH_INFO_BIN  := $(BIN_DIR)/ak3918_spiflash_info

PROGRAMS := \
    $(VIDEO_DUMP_BIN) \
    $(AUDIO_PLAY_BIN) \
    $(AUDIO_CAPTURE_BIN) \
    $(ISP_DUMP_BIN) \
    $(TESTING_BIN) \
    $(MOTOR_TEST_BIN) \
    $(SPIFLASH_INFO_BIN)

.PHONY: all clean

all: $(PROGRAMS)

$(VIDEO_DUMP_BIN): $(BUILD_DIR)/src/apps/video/dump.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(AUDIO_PLAY_BIN): $(BUILD_DIR)/src/apps/audio/playback.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(AUDIO_CAPTURE_BIN): $(BUILD_DIR)/src/apps/audio/capture.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(ISP_DUMP_BIN): $(BUILD_DIR)/src/apps/isp/dump_conf.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(TESTING_BIN): $(BUILD_DIR)/src/apps/testing/main.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -pthread -lrt -o $@

$(MOTOR_TEST_BIN): $(BUILD_DIR)/src/apps/motor/test.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(SPIFLASH_INFO_BIN): $(BUILD_DIR)/src/apps/storage/spiflash_info.o $(LIBAK)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< $(LIBAK) $(LDLIBS) -o $@

$(LIBAK): $(LIBAK_OBJS)
	@mkdir -p $(dir $@)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
