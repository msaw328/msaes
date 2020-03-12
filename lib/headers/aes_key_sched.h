#ifndef _AES_KEY_SCHED_H_
#define _AES_KEY_SCHED_H_

#include <string.h>
#include <stdint.h>

#include "aes_proc.h"

void aes_key_sched_generate(uint8_t* key, uint32_t* key_sched);

#endif
