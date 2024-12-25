#
# Cubic map Raylib program
# Copyright (C) 2024
#   

TARGET = tileson.elf
OBJS = tileson.o romdisk.o
KOS_ROMDISK_DIR = romdisk

KOS_CFLAGS += -I${KOS_PORTS}/include/raylib
KOS_CPPFLAGS += -I${KOS_PORTS}/include/raylib

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean: rm-elf
	-rm -f $(OBJS)

rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS)
	kos-c++ -o $(TARGET) -std=c++20 $(OBJS) -lraylib-tileson -lraylib -lGL -lkosutils 

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk.img
	$(KOS_STRIP) $(TARGET)

