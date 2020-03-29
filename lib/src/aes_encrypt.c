#include "aes_encrypt.h"

#include <stdio.h>

void aes_encrypt_block(uint32_t* input, uint32_t* key_sched, uint32_t* output, int aes_mode) {
    int rounds;
    switch(aes_mode) {
        default:
        case AES128:
            rounds = 10;
            break;
        
        case AES192:
            rounds = 12;
            break;

        case AES256:
            rounds = 14;
            break;
    }

    // copy block to output, then we ignore input and work on output as our state
    memcpy(output, input, 16);

    // Round 0
    // AddRoundKey

    uint32_t* current_key = key_sched;
    aes_proc_add_round_key(output, current_key);


    // TODO:change this ugly printf in encrypt.c to some sort of a macro behind a "#ifdef _DEBUG"
    // TODO:also prob add tests to the whole thing with test vectors from the official doc
    // test vectors are in https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf
    // Round 1 to 9/11/13
    for(int i = 0; i < rounds; i++) {
        printf("round[%d].start: ", i + 1);
        for(int j = 0; j < 16; j++) {
            printf("%02x", ((uint8_t*) output)[j]);
        }
        puts("");

        current_key += 4; // move to the next key

        // SubBytes
        aes_proc_sub_bytes(output);

        printf("round[%d].sbox:  ", i + 1);
        for(int j = 0; j < 16; j++) {
            printf("%02x", ((uint8_t*) output)[j]);
        }
        puts("");

        // ShiftRows
        aes_proc_shift_rows(output);

        printf("round[%d].srow:  ", i + 1);
        for(int j = 0; j < 16; j++) {
            printf("%02x", ((uint8_t*) output)[j]);
        }
        puts("");

        // MixColumns (not performed for last round)
        if(i < rounds - 1) {
            aes_proc_mix_columns(output);
            
            printf("round[%d].mcol:  ", i + 1);
            for(int j = 0; j < 16; j++) {
                printf("%02x", ((uint8_t*) output)[j]);
            }
            puts("");
        }

        // AddRoundKey
        aes_proc_add_round_key(output, current_key);
    }
}
