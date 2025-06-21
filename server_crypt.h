#ifndef SERVER_CRYPT_H
#define SERVER_CRYPT_H
#include <stdint.h>
#include <stddef.h>

void scramble(uint8_t *data, size_t len);
void descramble(uint8_t *data, size_t len);

#endif