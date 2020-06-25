#include <stdint.h>

#include "internal/aes_gf256.h"

// The mod polynomial in binary form
// Whole polynomial is 0x11b but we only care about lower byte
#define AES_GF_MOD 0x1b

// Not optimized GF multiplication based mostly on these two sources:
// https://gist.github.com/meagtan/dc1adff8d84bb895891d8fd027ec9d8c
// http://www.cs.utsa.edu/~wagner/laws/FFM.html
uint8_t aes_GF256_mul(uint8_t a, uint8_t b) {
    uint8_t res = 0;

    while(a) {
        if(a & 1)
            res ^= b;

        if(b & 0x80)
            b = (b << 1) ^ AES_GF_MOD;
        else
            b = b << 1;

        a = a >> 1;
    }

    return res;
}
