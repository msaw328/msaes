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
            fprintf(stderr, "%s(): " info_fmt, __func__, __VA_ARGS__); \
            fflush(stderr); \
            for(unsigned int j = 0; j < buffer_length; j++) { \
                fprintf(stderr, "%02x", ((uint8_t*) buffer)[j]); \
            } \
            fflush(stderr); \
            fprintf(stderr, "%s\n", ""); \
            fflush(stderr); \
        } while (0);
#else
    #define DEBUG_DUMP_BUFFER(buffer, buffer_length, info_fmt, ...) do {} while(0);
#endif

#endif
