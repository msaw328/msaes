#ifndef _AES_PUBLIC_H_
#define _AES_PUBLIC_H_

#include <stdint.h>

// Library API
void aes_encrypt_block(uint8_t* plaintext, uint8_t* key_sched, uint8_t* ciphertext, int aes_mode);
void aes_decrypt_block(uint8_t* ciphertext, uint8_t* key_sched, uint8_t* plaintext, int aes_mode);
void aes_key_sched_generate(uint8_t* key, uint8_t* key_sched_buffer, int aes_mode);

// Key size constants
#define AES128 0
#define AES192 1
#define AES256 2

// Length of buffer of uint8_t needed to contain key schedule for key size
#define AES128_KEYSCHED_SIZE 176
#define AES192_KEYSCHED_SIZE 208
#define AES256_KEYSCHED_SIZE 240

#endif
