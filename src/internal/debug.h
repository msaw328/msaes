#ifndef _AES_DEBUG_H_
#define _AES_DEBUG_H_

// Debugging utilities

#include <stdio.h>
#include <stdint.h>

// lots of resources online used to implement this macro but most importantly these two SO answers:
// https://stackoverflow.com/a/1644898
// https://stackoverflow.com/a/14251257
#ifdef AES_DEBUG
    #define DEBUG_DUMP_BUFFER(buffer, buffer_length, info_fmt, ...) \
        do { \
            fprintf(stderr, "%s:%d:%s(): " info_fmt, \
                __FILE__, __LINE__, __func__, \
                __VA_ARGS__); \
            for(int j = 0; j < buffer_length; j++) { \
                printf("%02x", ((uint8_t*) buffer)[j]); \
            } \
            puts(""); \
        } while (0);
#else
    #define DEBUG_DUMP_BUFFER(buffer, buffer_length, info_fmt, ...) do {} while(0);
#endif

#endif
