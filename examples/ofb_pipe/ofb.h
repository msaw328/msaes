#ifndef _OFB_H_
#define _OFB_H_

#include <stdint.h>
#include <stddef.h>

#include <msaes/aes.h>

// implementation of OFB mode
// TODO:Make OFB mode part of libmsaes.so
// i originally intended for the library to implement basic modes of necryption
// so that programs dont have to implement them themselves. This file and ofb.c should
// probably be moved to the lib source code and exposed in public api.

struct OFB_ctx_t {
    uint8_t IV[16];

    uint8_t keysched[AES128_KEYSCHED_SIZE];

    uint8_t keystream_block[16];
    int bytes_used; // bytes consumed from current keystream block, at 16 a new block should be generated
};
typedef struct OFB_ctx_t OFB_ctx_t;

// Initializes the key, the IV with random bytes and generates first 16 bytes of keystream
void OFB_init(OFB_ctx_t* c, uint8_t* key, uint8_t* IV);

// XORs n bytes from src with the internal keystream and places them in dst
void OFB_xor_bytes(OFB_ctx_t* c, uint8_t* src, uint8_t* dst, size_t n);

// Unrelated to OFB context, allows to generate a random 16 byte IV when encrypting
// When decrypting the IV should be read from the input stream
void OFB_gen_rand_IV(uint8_t* IV);

#endif
