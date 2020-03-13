#include <stdio.h>
#include <stdint.h>

#include "aes_key_sched.h"

int main() {
    // key taken from appendix C of https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf, easy to test
    uint8_t key[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };

    uint32_t key_sched[AES256_KEYSCHED_WORDS] = { 0 };

    aes_key_sched_generate(key, key_sched, AES256);

    for(int rd = 0; rd < 15; rd++) {
        printf("round %d: ", rd);
        uint8_t* ptr = (uint8_t*) (key_sched + (4 * rd));
        for(int i = 0; i < 16; i++) {
            printf("%02x", ptr[i]);
        }
        puts("");
    }
}
