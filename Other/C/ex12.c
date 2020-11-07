#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1024
#define ITEMS_MAX 50

typedef struct Item_ {
	char name[MAX];
	double price;
}Item;

void getInput(char* str);

int main() {
	char temp[MAX];
	char *trash;
	char testS[MAX];
	double testD;

	int itemCount = 0;
	Item items[ITEMS_MAX];

	char fileName[MAX] = "";
	printf("Enter filename: ");
	getInput(fileName);

	FILE* fileRead;
	fileRead = fopen(fileName, "r");
	while(fileRead != NULL){
		if (fgets(temp, MAX, fileRead) != NULL && itemCount < ITEMS_MAX) {
			temp[strcspn(temp, "\n")] = '\0';
			if (sscanf(temp, "%lf;%s", &testD, testS) < 2) {
				printf("Error: Bad formatting on line %d.", itemCount + 1);
				return 0;
				break;
			}
			items[itemCount].price = strtod(temp, &trash);
			for (int i = 0; i < strlen(trash); i++) {
				trash[i] = trash[i + 1];
			}
			strcpy(items[itemCount].name, trash);
			itemCount++;
		} else {
			break;
		}
	}
	fclose(fileRead);

	printf("%-40s%9s\n", "Name", "Price");
	for (int i = 0; i < itemCount; i++) {
		printf("%-40s%9.2lf\n", items[i].name, items[i].price);
	}

	return 0;
}

void getInput(char* str) {
	fgets(str, MAX, stdin);
	str[strcspn(str, "\n")] = '\0';
}