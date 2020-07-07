# What is this?
This project is a software implementation of AES. It supports encryption and decryption using 128, 192 and 256 bit keys, as described in the standard. Written in C for educational purposes. It does not use hardware extensions such as Intel AES-NI instruction set.

This is a reference implementation, it is not written with security or performance in mind and i __advise against__ using it in any project where security or performance is key.

# Dependencies
CMake is used for building, CTest for running unit tests, other than that there are no dependencies.

# How to build
```
$ mkdir build && cd build
$ cmake ..
$ make
```
It is also possible to specify build type (Debug/Release) explicitly:
```
$ cmake .. -DCMAKE_BUILD_TYPE=DEBUG
$ cmake .. -DCMAKE_BUILD_TYPE=RELEASE
```
Debug build displays information on stderr about state between steps specified in the standard (ShiftRows, MixColumns etc.). If you do not want this output, build RELEASE or redirect stderr somewhere else.

Running `make` produces a library `libmsaes.so` in the `build` directory as well as a few executables in `build/tests`. These executables are unit tests which can be ran using `ctest` or `make test` (CTest is a part of CMake).

If building DEBUG, one can also view raw test output (it is not displayed by default) by passing `--verbose` flag to `ctest`. I recommend redirecting the verbose output to a file since it gets pretty long:
```
$ cd build
$ ctest --verbose > ../test_output.txt
```
# Library API
TODO:Describe API

Before i do that you may look into header files in `include` and read comments.

# Examples
Go to [examples README file](examples/README.md).
