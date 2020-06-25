#ifndef _AES_GF256_H_
#define _AES_GF256_H_

// Operations in Galois field used in AES (so pretty much just multiplication)
// GF(2^8) with mod x^8 + x^4 + x^3 + x + 1

#include <stdint.h>

uint8_t aes_GF256_mul(uint8_t a, uint8_t b);

#endif
