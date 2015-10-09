TARGET = ApertureOS_Lib.a

CC=~/opt/cross/bin/i686-elf-gcc
CFLAGS = -ffreestanding -nostdlib -O3 -I. -Iinclude

OBJS = stubs.o

.PHONY: all

all:$(OBJS)
	ar -rcs $(TARGET) $(OBJS)

clean:
	rm -rf lib
	rm -rf $(OBJS)
	rm -rf $(TARGET)