#include <stdio.h>
#include <stdint.h>

#include "aes_key_sched.h"
#include "aes_encrypt.h"

int main() {
    // key taken from appendix C of https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf, easy to test
    uint8_t key[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };
    uint8_t plaintext[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
    uint8_t ciphertext[16] = { 0 };
    uint32_t key_sched[AES256_KEYSCHED_WORDS] = { 0 };

    aes_key_sched_generate(key, key_sched, AES256);
    aes_encrypt_block((uint32_t*) plaintext, key_sched, (uint32_t*) ciphertext, AES256);

    for(int rd = 0; rd < 11; rd++) {
        printf("round %d: ", rd);
        uint8_t* ptr = (uint8_t*) (key_sched + (4 * rd));
        for(int i = 0; i < 16; i++) {
            printf("%02x", ptr[i]);
        }
        puts("");
    }

    puts("ciphertext:");
    for(int i = 0; i < 16; i++) {
        printf("%02x", ciphertext[i]);
    }
    puts("");
}
