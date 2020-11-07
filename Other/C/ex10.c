#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#define MAX 1024

double getAverage(const int numC, const double arr[]);

int main() {
	int numberCount = 0, errorCount = 0, finalCount = 0;
	double numbers[MAX] = { 0 };
	double final = 0;

	FILE* myFile;
	myFile = fopen("text.txt", "r");
	if (myFile != NULL){
		if (fscanf(myFile, "%d", &numberCount) != 1) {
			printf("Please make sure that the first entry of the text file is an integer!");
			return 0;
		}
		for (int i = 0; i < numberCount; i++) {
			if (fscanf(myFile, "%lf", &numbers[i]) != 1){
				errorCount++;
			}
		}
	}
	fclose(myFile);

	finalCount = numberCount - errorCount;
	final = getAverage(finalCount, numbers);

	if (errorCount == 0) {
		printf("Average of %d numbers is %.2lf", numberCount, final);
	} else {
		printf("Error! Tried to read %d numbers but only %d numbers were read.\n", numberCount, finalCount);
		printf("Average of %d numbers is %.2lf", finalCount, final);
	}

	return 0;
}

double getAverage(const int numC, const double arr[]) {
	double temp = 0;

	for (int i = 0; i < numC; i++) {
		temp += arr[i];
	}

	return temp / numC;
}