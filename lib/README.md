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
git clone https://github.com/whytools/ypkg.git
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
make OPTIMIZE=speed # This will only run on the machine you are building on
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

4. Remove the artifacts

```bash
make clean
```