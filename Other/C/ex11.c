#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#define MAX 1024

void sort3(double pa[]);

int main() {
	double numbers[3] = { 0 };

	FILE* fileRead;
	fileRead = fopen("text.txt", "r");
	if (fileRead != NULL){
		for (int i = 0; i < 3; i++) {
			if (fscanf(fileRead, "%lf", &numbers[i]) != 1) {
				printf("Error reading a number!");
				return 0;
			}
		}
	}
	fclose(fileRead);

	sort3(numbers);

	FILE* fileWrite;
	fileWrite = fopen("text.txt", "w");
	if (fileWrite != NULL){
		fprintf(fileWrite, "%.2lf %.2lf %.2lf", numbers[0], numbers[1], numbers[2]);
	}
	fclose(fileWrite);

	return 0;
}

void sort3(double pa[]){
    double temp;

    if (pa[0] > pa[2]) {
        temp = pa[0];
        pa[0] = pa[2];
        pa[2] = temp;
    }

    if (pa[0] > pa[1]) {
        temp = pa[0];
        pa[0] = pa[1];
        pa[1] = temp;
    }

    if (pa[1] > pa[2]) {
        temp = pa[1];
        pa[1] = pa[2];
        pa[2] = temp;
    }
}