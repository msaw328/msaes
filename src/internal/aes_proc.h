#ifndef _AES_PROC_H_
#define _AES_PROC_H_

#include <stdint.h>

// word-granularity
// used by key sched
uint32_t aes_proc_sub_word(uint32_t word);
uint32_t aes_proc_rot_word(uint32_t word, int bytes);

// block-granularity
// used by encryption/decryption
void aes_proc_add_round_key(uint32_t* state, uint32_t* round_key);
void aes_proc_sub_bytes(uint32_t* state);
void aes_proc_shift_rows(uint32_t* state);
void aes_proc_mix_columns(uint32_t* state);

#endif
