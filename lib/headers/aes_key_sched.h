#ifndef _AES_KEY_SCHED_H_
#define _AES_KEY_SCHED_H_

#include <string.h>
#include <stdint.h>

#include "aes_proc.h"

#define AES128 0
#define AES192 1
#define AES256 2

#define AES128_KEYSCHED_WORDS 44
#define AES192_KEYSCHED_WORDS 52
#define AES256_KEYSCHED_WORDS 60

// performs the actual key sched algo, reads from key writes to key_sched
void aes_key_sched_generate(uint8_t* key, uint32_t* key_sched, int aes_mode);

#endif
