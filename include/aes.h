#ifndef _AES_H_PUBLIC_
#define _AES_H_PUBLIC_

#include <stdint.h>

// Library API
void aes_encrypt_block(uint32_t* input, uint32_t* key_sched, uint32_t* output, int aes_mode);
void aes_key_sched_generate(uint8_t* key, uint32_t* key_sched_buffer, int aes_mode);

// Key size constants
#define AES128 0
#define AES192 1
#define AES256 2

// Length of buffer of uint32_t needed to contain key schedule for key size (if allocating buffer of uint8_t remember to multiply times 4)
#define AES128_KEYSCHED_WORDS 44
#define AES192_KEYSCHED_WORDS 52
#define AES256_KEYSCHED_WORDS 60

#endif
