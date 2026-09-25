CFLAGS = -Wall -Werror -pedantic
LDLIBS = -lsqlite3
OPTIMIZE ?= debug
OPTFLAGS = -O0
OPTFLAGS_SMALL = -Os
OPTFLAGS_BALANCED = -O2
OPTFLAGS_BRRR = -Ofast -march=native
OBJECTS = ypkg.o consts.o db.o

.PHONY: all

all: libypkg.so

libypkg.so: $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS): %.o: src/%.c
ifeq ($(OPTIMIZE),debug)
	$(CC) $(OPTFLAGS) -c -fPIC $^ -o $@
endif
ifeq ($(OPTIMIZE),small)
	$(CC) $(OPTFLAGS_SMALL) -c -fPIC $^ -o $@
endif
ifeq ($(OPTIMIZE),release)
	$(CC) $(OPTFLAGS_BALANCED) -c -fPIC $^ -o $@
endif
ifeq ($(OPTIMIZE),speed)
	$(CC) $(OPTFLAGS_BRRR) -c -fPIC $^ -o $@
endif
ifeq ($(OPTIMIZE),brr)
	$(CC) $(OPTFLAGS_BRRR) -c -fPIC $^ -o $@
else
	$(CC) $(OPTFLAGS) -c -fPIC $^ -o $@
endif

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