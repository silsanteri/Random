#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1024

int main() {
    char c = NULL;
    char* str = (char*)malloc(sizeof(char));
    int i;

    FILE* fileWrite;
    fileWrite = fopen("text.txt", "w");
	if (fileWrite != NULL){
		while (strcmp(str, ".") != 0) {
			i = 0;
			str = (char*)realloc(str, (i + 1) * sizeof(char));

			printf("Enter a String: ");

			do {
				c = getc(stdin);

				str = (char*)realloc(str, (i + 1) * sizeof(char));
				str[i] = c;

				i++;
			} while (c != '\n');

			str[strcspn(str, "\n")] = '\0';

			if (strcmp(str, ".") != 0) {
				fprintf(fileWrite, "%d:%s\n", i - 1, str);
			}
		}
	}

    free(str);
    fclose(fileWrite);
    return 0;
}