# libypkg

C library for interacting with ypkg.

## Docs

## Building

### Requirements:

- glibc
- GNU make
- gcc/clang
- libsqlite3-dev

1. Clone the repository

```bash
git clone https://github.com/Delfi-CH/ypkg.git
cd ypkg/lib
```

2. Build the library

```bash
make
```
 
*Optional:*

*Build with optimisations:*
```bash
make OPTIMIZE=debug
make OPTIMIZE=balanced
make OPTIMIZE=speed # This will probably only run on the machine you are building on
```

*Force use gcc/clang:*
```bash
make CC=gcc
make CC=clang
```

3. Install the library and header

```bash
sudo make install

# if building as root
make install
```

*Note: On some systems the library might need to be installed to /usr/lib64 instead of the default /usr/lib. To install in /usr/lib64 run:* `sudo make install LIBDIR=/usr/lib64`

4. Build the examples

```bash
make examples
```

5. Remove the artifacts

```bash
make clean
```