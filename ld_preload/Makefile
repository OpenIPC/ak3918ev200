CROSS_COMPILE ?=
CC ?= $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Wextra -O2 -fPIC
CPPFLAGS ?=
LDFLAGS ?=
LIBS ?= -ldl -lpthread

TARGET ?= ipc_tracer.so
SRC := ipc_tracer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CPPFLAGS) $(CFLAGS) -shared -o $@ $< $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
