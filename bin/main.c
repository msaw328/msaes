#include <stdio.h>
#include <stdint.h>

#include "aes_key_sched.h"

int main() {
    // key taken from appendix C of https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf, easy to test
    uint8_t key[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    uint32_t key_sched[4 * 11] = { 0 };

    aes_key_sched_generate(key, key_sched);

    for(int rd = 0; rd < 11; rd++) {
        printf("round %d: ", rd);
        uint8_t* ptr = (uint8_t*) (key_sched + (4 * rd));
        for(int i = 0; i < 16; i++) {
            printf("%02x", ptr[i]);
        }
        puts("");
    }
}
