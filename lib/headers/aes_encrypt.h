#ifndef _AES_ENCRYPT_H_
#define _AES_ENCRYPT_H_

#include "aes_proc.h"

void aes_encrypt_block(uint32_t* input, uint32_t* key_sched, uint32_t* output, int aes_mode);

#endif
