#include <string.h>
#include <stdint.h>

#include "msaes/aes.h"
#include "internal/proc.h"

// Static precomputed RCON array
uint32_t const RCON[] = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };

void aes_key_sched_generate(uint8_t* key, uint8_t* key_sched_bytes, int aes_mode) {
    // work on 32 bit words internally
    uint32_t* key_sched = (uint32_t*) key_sched_bytes;

    int rounds;
    int key_bytes;

    switch(aes_mode) {
        default:
        case AES128:
            rounds = 10;
            key_bytes = 16;
            break;

        case AES192:
            rounds = 12;
            key_bytes = 24;
            break;

        case AES256:
            rounds = 14;
            key_bytes = 32;
            break;
    }

    memcpy(key_sched, key, key_bytes); // copy original key to the beginning of key sched buffer

    int mod = key_bytes / 4; // number of blocks when rcon is applied, how far to look for our last word etc. 4 for 128; 6 for 192; 8 for 256
    
    for(int i = mod; i < (rounds + 1) * 4; i++) { // +1 round for 0th round, aka round with the original key
        uint32_t tmp = key_sched[i - 1];

        if(i % mod == 0) {
            tmp = _aes_proc_rot_word(tmp, 1);
            tmp = _aes_proc_sub_word(tmp) ^ RCON[i / mod];
        } else if(aes_mode == AES256 && i % mod == 4) { // key size 256 gets special treatment - SBOX applied additional time
            tmp = _aes_proc_sub_word(tmp);
        }

        key_sched[i] = key_sched[i - mod] ^ tmp;
    }
}
