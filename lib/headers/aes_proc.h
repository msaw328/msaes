#ifndef _AES_PROC_H_
#define _AES_PROC_H_

#include <stdint.h>

uint32_t aes_proc_sub_word(uint32_t word);

uint32_t aes_proc_rot_word(uint32_t word, int bytes);

#endif
