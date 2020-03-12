#include "aes_key_sched.h"

uint32_t const RCON[] = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };

void aes_key_sched_generate(uint8_t* key, uint32_t* key_sched) {
    int rounds = 11; // 11 rounds for 128 bit key

    memcpy(key_sched, key, 16); // 16 bytes = 128 bits, copy key to the state

    uint32_t tmp;
    for(int i = 4; i < rounds * 4; i++) {
        tmp = key_sched[i - 1];

        if(i % 4 == 0) {
            tmp = aes_proc_rot_word(tmp, 1);
            tmp = aes_proc_sub_word(tmp) ^ RCON[i / 4];
        }

        key_sched[i] = key_sched[i - 4] ^ tmp;
    }
}
