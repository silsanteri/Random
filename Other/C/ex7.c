#include <stdio.h>
#include <ctype.h>
#define MAX 1024

void convertString(char* str);

int main() {
	char input[] = "";

	while(1){
		printf("Input a string: ");
		fgets(input, MAX, stdin);

		if ((strncmp(input, "stop", 4) == 0 || strncmp(input, "STOP", 4) == 0)) {
			break;
		}

		convertString(input);
		printf("Converted string: %s", input);
	}

	return 0;
}

void convertString(char* str){
	int i = 0;

	for(i = 0; i < strlen(str) - 1; i++){
		if(isblank(str[i])){
			str[i] = 95;
		}
	}
}