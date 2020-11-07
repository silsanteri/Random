#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <inttypes.h>
#define MAX 100

// I have no idea why the most outer while-loop breaks before it asks for the "check" variable.

typedef struct _chunk {
    uint8_t data[64];
    uint16_t size;
    uint16_t capacity;
    uint16_t crc;
} chunk;

void getInput(char* str);
uint16_t crc16(const uint8_t* data_p, unsigned int length);

int main() {
    char fileName[MAX], check[MAX];
    int chunkSize = 0, i = 0, c = 1;

    chunk* chunc = (chunk*)malloc(c * sizeof(chunk));

    while(1){
        FILE* fileRead;
        c = 1;
        chunc = (chunk*)realloc(chunc, c * sizeof(chunk));

        printf("Enter filename: ");
        getInput(fileName);

        printf("Enter chunk size: ");
        while (scanf("%d", &chunkSize) != 0 && chunkSize < 0 || chunkSize > 1024) {
            printf("Enter chunk size: ");
        }

        fileRead = fopen(fileName, "rb");

        while (!feof(fileRead)) {
            if (fileRead != NULL) {
                for (i = 0; i < chunkSize; i++) {
                    if (!feof(fileRead)) {
                        chunc[c - 1].data[i] = fgetc(fileRead);
                    }
                    else {
                        break;
                    }
                }
                printf("\n\n");

                chunc[c - 1].size = i;
                chunc[c - 1].capacity = chunkSize;
                chunc[c - 1].crc = crc16(chunc[c - 1].data, chunc[c - 1].size);

                printf("Chunk number: %d\nSize: %d\nCapacity: %d\nCRC: %#06X\n\n", c, chunc[c - 1].size, chunc[c - 1].capacity, chunc[c - 1].crc);

                c++;
                chunc = (chunk*)realloc(chunc, c * sizeof(chunk));
            }
        }

        free(chunc);
        fclose(fileRead);

        printf("Scan another file?: ");
        getInput(check);

        if (strcmp(check, "yes") != 0) {
            break;
        }
    }
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