#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "msaes/aes.h"

int main() {
    // Test data taken from FIPS 197 Appendix C
    // https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf

    uint8_t expected_plaintext[16] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
    };

    uint8_t key_sched[AES192_KEYSCHED_SIZE] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,

        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x58, 0x46, 0xf2, 0xf9, 0x5c, 0x43, 0xf4, 0xfe,

        0x54, 0x4a, 0xfe, 0xf5, 0x58, 0x47, 0xf0, 0xfa,
        0x48, 0x56, 0xe2, 0xe9, 0x5c, 0x43, 0xf4, 0xfe,

        0x40, 0xf9, 0x49, 0xb3, 0x1c, 0xba, 0xbd, 0x4d,
        0x48, 0xf0, 0x43, 0xb8, 0x10, 0xb7, 0xb3, 0x42,

        0x58, 0xe1, 0x51, 0xab, 0x04, 0xa2, 0xa5, 0x55,
        0x7e, 0xff, 0xb5, 0x41, 0x62, 0x45, 0x08, 0x0c,

        0x2a, 0xb5, 0x4b, 0xb4, 0x3a, 0x02, 0xf8, 0xf6,
        0x62, 0xe3, 0xa9, 0x5d, 0x66, 0x41, 0x0c, 0x08,

        0xf5, 0x01, 0x85, 0x72, 0x97, 0x44, 0x8d, 0x7e,
        0xbd, 0xf1, 0xc6, 0xca, 0x87, 0xf3, 0x3e, 0x3c,

        0xe5, 0x10, 0x97, 0x61, 0x83, 0x51, 0x9b, 0x69,
        0x34, 0x15, 0x7c, 0x9e, 0xa3, 0x51, 0xf1, 0xe0,

        0x1e, 0xa0, 0x37, 0x2a, 0x99, 0x53, 0x09, 0x16,
        0x7c, 0x43, 0x9e, 0x77, 0xff, 0x12, 0x05, 0x1e,

        0xdd, 0x7e, 0x0e, 0x88, 0x7e, 0x2f, 0xff, 0x68,
        0x60, 0x8f, 0xc8, 0x42, 0xf9, 0xdc, 0xc1, 0x54,

        0x85, 0x9f, 0x5f, 0x23, 0x7a, 0x8d, 0x5a, 0x3d,
        0xc0, 0xc0, 0x29, 0x52, 0xbe, 0xef, 0xd6, 0x3a,

        0xde, 0x60, 0x1e, 0x78, 0x27, 0xbc, 0xdf, 0x2c,
        0xa2, 0x23, 0x80, 0x0f, 0xd8, 0xae, 0xda, 0x32,

        0xa4, 0x97, 0x0a, 0x33, 0x1a, 0x78, 0xdc, 0x09,
        0xc4, 0x18, 0xc2, 0x71, 0xe3, 0xa4, 0x1d, 0x5d
    };
    
    uint8_t ciphertext[16] = {
        0xdd, 0xa9, 0x7c, 0xa4, 0x86, 0x4c, 0xdf, 0xe0,
        0x6e, 0xaf, 0x70, 0xa0, 0xec, 0x0d, 0x71, 0x91
    };
    
    // Actual test
    uint8_t plaintext[16] = { 0 };
    aes_decrypt_block(ciphertext, key_sched, plaintext, AES192);

    return (memcmp(plaintext, expected_plaintext, 16) == 0) ? 0 : 1;
}
