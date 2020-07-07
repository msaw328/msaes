#include "ofb.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <msaes/aes.h>

void _next_keystream_block(OFB_ctx_t* c) {
    uint8_t tmp[16];
    aes_encrypt_block(c->keystream_block, c->keysched, tmp, AES128);
    memcpy(c->keystream_block, tmp, 16);
}

void OFB_init(OFB_ctx_t* c, uint8_t* key, uint8_t* iv) {
    // IV
    memcpy(c->IV, iv, 16);

    // key
    aes_key_sched_generate(key, c->keysched, AES128);

    // keystream block
    aes_encrypt_block(c->IV, c->keysched, c->keystream_block, AES128);

    c->bytes_used = 0;
}

void OFB_xor_bytes(OFB_ctx_t* c, uint8_t* src, uint8_t* dst, size_t n) {
    unsigned int count = 0;

    while(count < n) {
        dst[count] = src[count] ^ c->keystream_block[c->bytes_used];

        count++;
        c->bytes_used++;

        if(c->bytes_used >= 16) {
            _next_keystream_block(c);
            c->bytes_used = 0;
        }
    }
}

void OFB_gen_rand_IV(uint8_t* iv) {
    int rand_fd = open("/dev/urandom", O_RDONLY);
    read(rand_fd, iv, 16);
    close(rand_fd);
}
