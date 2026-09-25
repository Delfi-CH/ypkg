CFLAGS = -Wall -Werror -pedantic
LDLIBS = -lsqlite3
OBJECTS = ypkg.o consts.o db.o

.PHONY: all

all: libypkg.so

libypkg.so: $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS): %.o: src/%.c
	$(CC) -c -fPIC $^ -o $@

.PHONY: clean

clean:
	rm -rf *.o *.so *.a

PREFIX ?= /usr
LIBDIR = $(PREFIX)/lib
INCLUDEDIR = $(PREFIX)/include

.PHONY: install

install:
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 libypkg.so $(DESTDIR)$(LIBDIR)/libypkg.so
	install -m 644 include/ypkg.h $(DESTDIR)$(INCLUDEDIR)/ypkg.h