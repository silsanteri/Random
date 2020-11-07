#include <stdio.h>
#include <ctype.h>
#define MAX 1024

void convertFirsts(char* str);

int main() {
	char input[] = "";

	while(1){
		printf("Input a string: ");
		fgets(input, MAX, stdin);

		if ((strncmp(input, "stop", 4) == 0 || strncmp(input, "STOP", 4) == 0)) {
			break;
		}

		convertFirsts(input);
		printf("Converted string: %s", input);
	}

	return 0;
}

void convertFirsts(char* str){
	int i = 0;

	for(i = 0; i < strlen(str) - 1; i++){
		if(i == 0){
			str[i] = toupper(str[i]);
		} else if (isblank(str[i - 1])) {
			str[i] = toupper(str[i]);
		}
	}
}