#include <stdint.h>
#include <string.h>

#include "msaes/padding.h"

int main() {
    // 1 Block of padding
    if(AES_PAD_BUF_LEN(15) != 16) return 1;

    // Full block of padding
    if(AES_PAD_BUF_LEN(16) != 32) return 2;

    // Random buffer
    if(AES_PAD_BUF_LEN(34) != 48) return 3;

    return 0;
}
