#ifndef _AES_PUBLIC_H_
#define _AES_PUBLIC_H_

#include <stdint.h>

// Implementation of AES algorithm: encryption, decryption and key expansion (key schedule generation)
// for 128, 192 and 256 bit keys

// Library API
// 'aes_key_size' is one of the key size constants defined below
// in key_sched_generate(), key_sched_buffer has to be N bytes long, where N is one of
// the KEYSCHED_SIZE cosntants defined below (according to key length)
void aes_encrypt_block(uint8_t* plaintext, uint8_t* key_sched, uint8_t* ciphertext, int aes_key_size);
void aes_decrypt_block(uint8_t* ciphertext, uint8_t* key_sched, uint8_t* plaintext, int aes_key_size);
void aes_key_sched_generate(uint8_t* key, uint8_t* key_sched_buffer, int aes_key_size);

// Key size constants
#define AES128 0
#define AES192 1
#define AES256 2

// Length of buffer of uint8_t needed to contain key schedule for key size
#define AES128_KEYSCHED_SIZE 176
#define AES192_KEYSCHED_SIZE 208
#define AES256_KEYSCHED_SIZE 240

#endif
