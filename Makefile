TARGET = libraylib-tileson.a
OBJS = source/raylib-tileson.o

CPPFLAGS += -std=c++20 -Iinclude -I${KOS_PORTS}/include/raylib


PREFIX ?= $(KOS_PORTS)
INSTALL_PATH ?= $(DESTDIR)$(PREFIX)/lib
INSTALL_INCLUDE ?= $(DESTDIR)$(PREFIX)/include

all: $(OBJS) subdirs linklib

linklib:
	mkdir lib
	rm -f lib/${TARGET}
	${KOS_AR} rcs lib/${TARGET} ${OBJS} ${LIB_OBJS}

clean:
	rm -f ${OBJS} ${LIB_OBJS} lib/${TARGET}

install:
	cp lib/$(TARGET) $(INSTALL_PATH)
	cp include/*.h $(INSTALL_INCLUDE)

include ${KOS_BASE}/Makefile.rules
