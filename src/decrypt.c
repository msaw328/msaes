#include <string.h>
#include <stdint.h>

#include "aes/aes.h"
#include "internal/proc.h"
#include "internal/debug.h"

void aes_decrypt_block(uint8_t* input_bytes, uint8_t* key_sched_bytes, uint8_t* output_bytes, int aes_mode) {
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

    DEBUG_DUMP_BUFFER(output, 16, "round[%2d].iinput:  ", 0);

    // each key is 4 * 32 bit words from the key_sched buffer
    // we start from the last key
    uint32_t* current_key = key_sched + 4 * rounds;

    DEBUG_DUMP_BUFFER(current_key, 16, "round[%2d].ik_sch:  ", 0);

    _aes_proc_add_round_key(output, current_key);

    // Round 1 to 10/12/14
    for(int i = 0; i < rounds; i++) {
        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].istart:  ", i + 1);

        // InvShiftRows
        _aes_proc_inv_shift_rows(output);

        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].is_row:  ", i + 1);

        // InvSubBytes
        _aes_proc_inv_sub_bytes(output);

        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].is_box:  ", i + 1);

        current_key -= 4; // move to the next key

        DEBUG_DUMP_BUFFER(current_key, 16, "round[%2d].ik_sch:  ", i + 1);

        // AddRoundKey
        _aes_proc_add_round_key(output, current_key);

        DEBUG_DUMP_BUFFER(output, 16, "round[%2d].ik_add:  ", i + 1);

        // InvMixColumns (not performed for last round)
        if(i < rounds - 1) {
            _aes_proc_inv_mix_columns(output);
            
            DEBUG_DUMP_BUFFER(output, 16, "round[%2d].im_col:  ", i + 1);
        }
    }

    DEBUG_DUMP_BUFFER(output, 16, "round[%2d].ioutput: ", rounds);
}
