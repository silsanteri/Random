#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <inttypes.h>
#define MAX 100

typedef struct _chunk {
    uint8_t data[64];
    uint16_t size;
    uint16_t crc;
} chunk;

void getInput(char* str);
uint16_t crc16(const uint8_t* data_p, unsigned int length);

int main() {
    char fileName[MAX];
    int i = 0, c = 1;

    chunk* chunc = (chunk*)malloc(c * sizeof(chunk));

    FILE* fileRead;

    printf("Enter filename: ");
    getInput(fileName);
    fileRead = fopen(fileName, "rb");

    if (fileRead != NULL) {
        while(1){
            for (i = 0; i < 64; i++) {
                if (!feof(fileRead)) {
                    chunc[c - 1].data[i] = fgetc(fileRead);
                } else {
                    break;
                }
            }
            printf("\n\n");

            chunc[c - 1].size = i;
            chunc[c - 1].crc = crc16(chunc[c - 1].data, chunc[c - 1].size);

            printf("Chunk number: %d\nSize: %d\n CRC: %#06X\n\n", c, chunc[c - 1].size, chunc[c - 1].crc);

            c++;
            chunc = (chunk*)realloc(chunc, c * sizeof(chunk));

            if (feof(fileRead)) {
                break;
            }
        }
    }

    free(chunc);
    fclose(fileRead);
    return 0;
}

void getInput(char* str) {
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
}

uint16_t crc16(const uint8_t* data_p, unsigned int length) {
    uint8_t x;
    uint16_t crc = 0xFFFF;
    while (length--) {
        x = crc >> 8 ^ *data_p++;
        x ^= x >> 4;
        crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
    }
    return crc;
}