#include <string.h>
#include <stdint.h>

#include "aes.h"
#include "internal/aes_proc.h"
#include "internal/aes_debug.h"

void aes_encrypt_block(uint8_t* input_bytes, uint8_t* key_sched_bytes, uint8_t* output_bytes, int aes_mode) {
    // work on 32 bit words internally
    uint32_t* input = (uint32_t*) input_bytes;
    uint32_t* key_sched = (uint32_t*) key_sched_bytes;
    uint32_t* output = (uint32_t*) output_bytes;

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

    DEBUG_DUMP_BUFFER(output, 16, "round[%2d].input:  ", 0);

    // each key is 4 * 32 bit words from the key_sched buffer
    uint32_t* current_key = key_sched;

    DEBUG_DUMP_BUFFER(current_key, 16, "round[%2d].k_sch:  ", 0);

    aes_proc_add_round_key(output, current_key);

    // test vectors are in https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf
    // Round 1 to 9/11/13
    for(int i = 0; i < rounds; i++) {
        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].start:  ", i + 1);

        // SubBytes
        aes_proc_sub_bytes(output);

        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].s_box:  ", i + 1);

        // ShiftRows
        aes_proc_shift_rows(output);

        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].s_row:  ", i + 1);

        // MixColumns (not performed for last round)
        if(i < rounds - 1) {
            aes_proc_mix_columns(output);
            
            DEBUG_DUMP_BUFFER(output, 16, "round[%2d].m_col:  ", i + 1);
        }

        current_key += 4; // move to the next key

        DEBUG_DUMP_BUFFER(current_key, 16, "round[%2d].k_sch:  ", i + 1);

        // AddRoundKey
        aes_proc_add_round_key(output, current_key);
    }

    DEBUG_DUMP_BUFFER(output, 16, "round[%2d].output: ", rounds);
}
