#include "server_crypt.h"

static uint8_t rotl8(uint8_t val, unsigned int shift) {
    return (val << shift) | (val >> (8 - shift));
}


static uint8_t rotr8(uint8_t val, unsigned int shift) {
    return (val >> shift) | (val << (8 - shift));
}

void scramble(uint8_t *data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        data[i] = rotl8(data[i], 2 );
    }
}

void descramble(uint8_t *data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        data[i] = rotr8(data[i], 2 );
    }
}