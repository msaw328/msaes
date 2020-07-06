#include <stdint.h>
#include <string.h>

#include "msaes/padding.h"

int main() {
    // 1 byte of padding
    uint8_t padded_data1[16] = {
        0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
        0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x80
    };

    if(aes_unpad_buf_len(padded_data1, 16) != 15) return 1;
    
    // Full block of padding
    uint8_t padded_data2[32] = {
        0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
        0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    if(aes_unpad_buf_len(padded_data2, 32) != 16) return 2;

    // Random buffer
    uint8_t padded_data3[16] = {
        0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
        0x12, 0x12, 0x12, 0x80, 0x00, 0x00, 0x00, 0x00
    };

    if(aes_unpad_buf_len(padded_data3, 16) != 11) return 3;

    return 0;
}
