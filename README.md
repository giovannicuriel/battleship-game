# Battleship!

This is (will be) a simple game. Educational purpose only ;D

## How to build

Dependencies:
 - SDL
 - Google Test (+Google mock) if you want to run tests
 - GCC version with support for C++ 20 (don't remember the lowest version with
   support, I'll check that - brb ;D)

## How to run tests

Just configure this application with `--enable-unit-tests`:

```bash
./autogen.sh
./configure --enable-unit-tests
make check
```
