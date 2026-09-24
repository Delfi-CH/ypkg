CFLAGS = -Wall -Werror -pedantic
CC = gcc

all: libypkg.so

libypkg.so: ypkg.o types.o
	$(CC) $(CFLAGS) -shared -o libypkg.so ypkg.o types.o

ypkg.o: src/ypkg.c 
	$(CC) $(CFLAGS) -c -fPIC -o ypkg.o src/ypkg.c

types.o: src/types.c
	$(CC) $(CFLAGS) -c -fPIC -o types.o src/types.c

.PHONY: clean

clean:
	rm -rf out

PREFIX ?= /usr
LIBDIR = $(PREFIX)/lib

install: all 
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 libypkg.so $(DESTDIR)$(LIBDIR)/libypkg.so