What is this?

This project is a software implementation of AES. It supports encryption
and decryption using 128, 192 and 256 bit keys, as described in the
standard. Written in C for educational purposes. It does not use
hardware extensions such as Intel AES-NI instruction set.

This is a reference implementation, it is not written with security or
performance in mind and i advise against using it in any project where
security or performance is key.

Dependencies

CMake is used for building, CTest for running unit tests. Code uses
standard libc and linux headers extensively.

How to build

    $ mkdir build && cd build
    $ cmake ..
    $ make

It is also possible to specify build type (Debug/Release) explicitly:

    $ cmake -DCMAKE_BUILD_TYPE=DEBUG ..
    $ cmake -DCMAKE_BUILD_TYPE=RELEASE ..

Debug build displays information about state between steps specified in
the standard (ShiftRows, MixColumns etc.) to stderr.

Running make produces a library libmsaes.so in the build directory as
well as a few executables in build/tests. These executables are unit
tests which can be ran using ctest or make test.

By default ctest does not display raw test output. To display it use the
--verbose option:

    $ cd build
    $ ctest --verbose > ../test_output.txt

Library API

msaes/aes.h - Encryption/Decryption using AES

In all functions aes_key_size should be set to either of: AES128,
AES192, AES256 and key_exp should point to a buffer that is at least
AES128_KEYSCHED_SIZE, AES192_KEYSCHED_SIZE, AES256_KEYSCHED_SIZE bytes
long, depending on key size used. Also, p and c should point to valid
buffers at least 16 bytes in length.

-   void aes_key_sched_generate(uint8_t* key, uint8_t* key_exp, int aes_key_size);

    You probably wanna call this first.

    Takes a 16/24/32 byte key and expands it into the key_exp buffer.

-   void aes_encrypt_block(uint8_t* p, uint8_t* key_exp, uint8_t* c, int aes_key_size);

    Encrypts a block of plaintext pointed to by p and saves result in a
    buffer pointed to by c.

-   void aes_decrypt_block(uint8_t* c, uint8_t* key_exp, uint8_t* p, int aes_key_size);

    Decrypts a block of ciphertext pointed to by c and saves result in a
    buffer pointed to by p.

------------------------------------------------------------------------

msaes/padding.h - ISO9797 method 2 padding

-   AES_PAD_BUF_LEN(unpad_size) (Macro)

    Calculates the buffer size in bytes needed to contain data of length
    unpad_size + padding.

-   size_t aes_unpad_buf_len(uint8_t* pad_buf, size_t pad_size);

    Calculates the length of unpadded data based on the contents of
    pad_buf (which contains original data + padding).

-   void aes_pad_buffer(uint8_t* unpad_buf, uint8_t* pad_buf, size_t unpad_size);

    Copies unpad_size number of bytes fron unpad_buf into pad_buf and
    pads the data.

-   void aes_unpad_buffer(uint8_t* pad_buf, uint8_t* unpad_buf, size_t unpad_size);

    Copies unpad_size number of bytes from pad_buf into unpad_buf. Yep,
    literally just a memcpy().

Examples

Go to examples (not built by default, to build them run make examples).
