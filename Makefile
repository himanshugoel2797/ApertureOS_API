TARGET = ApertureOS_Lib.a

CC=clang
CFLAGS = -ffreestanding -nostdlib -O3 -I. -Iinclude

OBJS = syscalls.o

.PHONY: all

all:$(OBJS)
	ar -rc $(OBJS) 
	mv $(TARGET) lib/$(TARGET)

clean:
	rm -rf lib
	rm -rf $(OBJS)
	rm -rf $(TARGET)