#include <string.h>

#include "internal/aes_proc.h"
#include "internal/aes_sbox.h"
#include "internal/aes_gf256.h"

// word granularity (32 bits)
// used by key sched
uint32_t aes_proc_sub_word(uint32_t word) {
    uint32_t res = 0;
    uint8_t* in = (uint8_t*) &word;
    uint8_t* out = (uint8_t*) &res;

    for(int i = 0; i < 4; i++) {
        out[i] = SUB_BYTE(in[i]);
    }

    return res;
}

uint32_t aes_proc_rot_word(uint32_t word, int bytes) {
    int bitshift = bytes * 8;
    return (word >> bitshift) | (word << (32 - bitshift));
}

// block granularity (128 bits)
// used by encryption
void aes_proc_add_round_key(uint32_t* state, uint32_t* round_key) {
	for(int i = 0; i < 4; i++) {
		state[i] ^= round_key[i];
	}
}

void aes_proc_sub_bytes(uint32_t* state) {
	for(int i = 0; i < 4; i++) {
		state[i] = aes_proc_sub_word(state[i]);
	}
}

// index into a 16 byte block as a 4x4 byte matrix (for shift rows and inv shift rows)
#define IDX(x, y) (y + x * 4)

void aes_proc_shift_rows(uint32_t* state) {
	uint8_t* state8 = (uint8_t*) state; // this step requires a byte level access
	uint8_t tmp;

	// 1st row - nothing

	// 2nd row
	tmp = state8[IDX(0, 1)];
	state8[IDX(0, 1)] = state8[IDX(1, 1)];
	state8[IDX(1, 1)] = state8[IDX(2, 1)];
	state8[IDX(2, 1)] = state8[IDX(3, 1)];
	state8[IDX(3, 1)] = tmp;

	// 3rd row
	tmp = state8[IDX(0, 2)];
	state8[IDX(0, 2)] = state8[IDX(2, 2)];
	state8[IDX(2, 2)] = tmp;

	tmp = state8[IDX(1, 2)];
	state8[IDX(1, 2)] = state8[IDX(3, 2)];
	state8[IDX(3, 2)] = tmp;

	// 4th row
	tmp = state8[IDX(3, 3)];
	state8[IDX(3, 3)] = state8[IDX(2, 3)];
	state8[IDX(2, 3)] = state8[IDX(1, 3)];
	state8[IDX(1, 3)] = state8[IDX(0, 3)];
	state8[IDX(0, 3)] = tmp;
}

void aes_proc_mix_columns(uint32_t* state) {
	for(int i = 0; i < 4; i++) {
		uint8_t* state8 = (uint8_t*) state;
		uint8_t result[4] = { 0 };

		result[0] = aes_GF256_mul(state8[0], 2) ^ aes_GF256_mul(state8[1], 3) ^               state8[2]     ^               state8[3];
		result[1] =               state8[0]     ^ aes_GF256_mul(state8[1], 2) ^ aes_GF256_mul(state8[2], 3) ^               state8[3];
		result[2] =               state8[0]     ^               state8[1]     ^ aes_GF256_mul(state8[2], 2) ^ aes_GF256_mul(state8[3], 3);
		result[3] = aes_GF256_mul(state8[0], 3) ^               state8[1]     ^               state8[2]     ^ aes_GF256_mul(state8[3], 2);

		memcpy(state, result, 4);
		state++; // next column
	}
}
