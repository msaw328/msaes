#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "internal/debug.h"

void aes_pad_buffer(uint8_t* unpad_buf, uint8_t* pad_buf, size_t unpad_size) {
    memcpy(pad_buf, unpad_buf, unpad_size);

    pad_buf[unpad_size] = 0x80;

    unpad_size++;

    while(unpad_size % 16 != 0) {
        pad_buf[unpad_size] = 0x00;
        unpad_size++;
    }
}

size_t aes_unpad_buf_len(uint8_t* pad_buf, size_t pad_size) {
    size_t ctr = pad_size;

    while(pad_buf[ctr - 1] == 0x00)
        ctr--;

#ifdef AES_DEBUG
    if(pad_buf[ctr - 1] != 0x80)
        DEBUG_DUMP_BUFFER(pad_buf, pad_size, "%s", "Padding byte not 0x80");
#endif

    return ctr - 1;
}

void aes_unpad_buffer(uint8_t* pad_buf, uint8_t* unpad_buf, size_t unpad_size) {
    memcpy(unpad_buf, pad_buf, unpad_size);
}
