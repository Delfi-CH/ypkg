CFLAGS = -Wall -Werror -pedantic
LDLIBS = -lsqlite3
CC = gcc

OBJECTS = ypkg.o types.o db.o

all: libypkg.so

libypkg.so: $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS): %.o: src/%.c
	$(CC) -c -fPIC $^ -o $@

.PHONY: clean

clean:
	rm -rf *.o *.so

PREFIX ?= /usr
LIBDIR = $(PREFIX)/lib

install: all 
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 libypkg.so $(DESTDIR)$(LIBDIR)/libypkg.so