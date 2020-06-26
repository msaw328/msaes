#ifndef _AES_PROC_H_
#define _AES_PROC_H_

// AES base procedures

#include <stdint.h>

// word granularity (32 bits)
// used by key sched
uint32_t aes_proc_sub_word(uint32_t word);
uint32_t aes_proc_rot_word(uint32_t word, int bytes);

// block granularity (128 bits)
// used by encryption
void aes_proc_add_round_key(uint32_t* state, uint32_t* round_key);
void aes_proc_sub_bytes(uint32_t* state);
void aes_proc_shift_rows(uint32_t* state);
void aes_proc_mix_columns(uint32_t* state);

// block granularity (128 bits), inverse operations
// used by decryption
//void aes_proc_inv_add_round_key(uint32_t* state, uint32_t* round_key); //its the same as add_round_key so unimplemented
void aes_proc_inv_sub_bytes(uint32_t* state);
void aes_proc_inv_shift_rows(uint32_t* state);
void aes_proc_inv_mix_columns(uint32_t* state);

#endif
