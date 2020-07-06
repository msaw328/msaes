#ifndef _UTILS_PUBLIC_H_
#define _UTILS_PUBLIC_H_

#include <stddef.h>
#include <stdint.h>

// This is an implementation of padding algorithm described in ISO9797 (method 2)
// Even though it originally worked with bits, it works just fine with bytes as well.
// Instead of appending a single bit, we append a byte of value 0x80, the results are the same.

// The data does NOT have to be null terminated, if you want to pad a null terminated string
// you have to include the null byte in 'unpad_size', for instance by using strlen() + 1

// Calculates the buffer size in bytes needed to contain data of length 'unpad_size' + padding
// It is implemented as a macro, as its a simple mathematical operation so its not worth the function call overhead
#define AES_PAD_BUF_LEN(unpad_size) (unpad_size + 16 - (unpad_size % 16))

// Copies 'unpad_size' number of bytes fron unpad_buf into pad_buf and pads the data according to the ISO9797 algorithm
void aes_pad_buffer(uint8_t* unpad_buf, uint8_t* pad_buf, size_t unpad_size);

// Calculates the length of unpadded data based on the contents of pad_buf (which contains original data + padding)
size_t aes_unpad_buf_len(uint8_t* pad_buf, size_t pad_size);

// Copies 'unpad_size' number of bytes from pad_buf into unpad_buf
void aes_unpad_buffer(uint8_t* pad_buf, uint8_t* unpad_buf, size_t unpad_size);

// Example usage:
// PADDING:
// uint8_t data[N];
// uint8_t padded_data[AES_PAD_BUF_LEN(N)];
// aes_pad_buffer(data, padded_data, N);
//
// UNPADDING:
// uint8_t padded_data[M];
// size_t unpad_size = aes_unpad_buf_len(padded_data, M);
// uint8_t data[unpad_size];
// aes_unpad_buffer(padded_data, data, unpad_size);
#endif
