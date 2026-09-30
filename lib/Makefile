CFLAGS = -Wall -Werror -pedantic
LDLIBS = -lsqlite3 -liniparser
OPTIMIZE ?= debug
OPTFLAGS = -O0
BUILD_DIR = build
OBJECTS = $(BUILD_DIR)/ypkg.o $(BUILD_DIR)/consts.o $(BUILD_DIR)/db.o $(BUILD_DIR)/config.o

ifeq ($(OPTIMIZE),debug)
OPTFLAGS = -O0
else ifeq ($(OPTIMIZE),small)
OPTFLAGS = -Os
else ifeq ($(OPTIMIZE),release)
OPTFLAGS = -O2
else ifeq ($(OPTIMIZE),speed)
OPTFLAGS = -Ofast -march=native
else ifeq ($(OPTIMIZE),brr)
OPTFLAGS = -Ofast -march=native
else
$(error Unknown OPTIMIZE value: $(OPTIMIZE))
endif

.PHONY: all

all: $(BUILD_DIR) libypkg.so

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir --parents $(BUILD_DIR)/examples

libypkg.so: $(BUILD_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS) $(LDLIBS)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c -fPIC $^ -o $@

.PHONY: clean

clean:
	rm -rf *.o *.so *.a docs $(BUILD_DIR)

PREFIX ?= /usr
LIBDIR = $(PREFIX)/lib
INCLUDEDIR = $(PREFIX)/include

.PHONY: install

install: $(BUILD_DIR)
	install -d $(DESTDIR)$(LIBDIR)
	install -d $(DESTDIR)$(INCLUDEDIR)
	install -m 644 libypkg.so $(DESTDIR)$(LIBDIR)/libypkg.so
	install -m 644 include/ypkg.h $(DESTDIR)$(INCLUDEDIR)/ypkg.h

docs:
	doxygen

EXAMPLE_LIST = init

.PHONY: examples

examples: $(BUILD_DIR) $(EXAMPLE_LIST)

$(EXAMPLE_LIST): %: examples/%.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/examples/$@ -lypkg