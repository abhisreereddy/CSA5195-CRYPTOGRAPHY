#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
void md5(const char *initial_message, uint8_t *digest);
int main() {
    const char *message = "Hello, MD5!";
    uint8_t digest[16];
    md5(message, digest);
    printf("Message: %s\n", message);
    printf("MD5 Digest: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}
void md5(const char *initial_message, uint8_t *digest) {
    uint32_t r[] = {
        7, 12, 17, 22,
        5, 9, 14, 20,
        4, 11, 16, 23,
        6, 10, 15, 21
    };
    uint32_t k[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821
    };
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;
    size_t initial_len = strlen(initial_message);
    size_t padded_len = initial_len + 1 + 8 + (64 - ((initial_len + 9) % 64));
    char *message = (char *)malloc(padded_len);
    strcpy(message, initial_message);
    message[initial_len] = 0x80;  
    for (size_t i = initial_len + 1; i < padded_len - 8; i++) {
        message[i] = 0;  
    }
    uint64_t bit_len = 8 * initial_len;
    memcpy(message + padded_len - 8, &bit_len, 8);
    for (size_t i = 0; i < padded_len; i += 64) {
        uint32_t *w = (uint32_t *)(message + i);
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        for (int j = 0; j < 64; j++) {
            uint32_t f, g;
            if (j < 16) {
                f = (b & c) | ((~b) & d);
                g = j;
            } else if (j < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * j) % 16;
            }
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + k[j] + w[g]), r[j]);
            a = temp;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
    memcpy(digest, &h0, 4);
    memcpy(digest + 4, &h1, 4);
    memcpy(digest + 8, &h2, 4);
    memcpy(digest + 12, &h3, 4);
    free(message);
}

