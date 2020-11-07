#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 1024
#define CARS 15

void printList(char* str, struct Cars* vroom);
bool changeStatus(char* str, struct Cars* vroom);
void getInput(char* str);
void parseInput(char* str);
void printWelcome();
void doHelp();
void doPrint(char* str, struct Cars* vroom);
void doStatus(char* str, struct Cars* vroom);
void doUnrecognized();
void doExit();

struct Cars {
	char make[MAX];
	char model[MAX];
	char category[MAX];
	char plate[MAX];
	int mileage;
	bool status;
};

int main() {
	struct Cars rentals[CARS] = {
		{"Mitsubishi",	"Lancer Evo",		"PCNR", "AAA-111",	105420, false},
		{"Nissan",		"350Z",				"PCMR",	"BBB-222",	46420,	false},
		{"Nissan",		"Silvia S15-R",		"PCMR", "CCC-333",	88420,	false},
		{"Nissan",		"Skyline GT-R32",	"PCMR", "DDD-444",	48420,	false},
		{"Nissan",		"Skyline GT-R33",	"PCMR", "EEE-555",	33420,	true},
		{"Nissan",		"Skyline GT-R34",	"PCMR", "FFF-666",	96669,	false},
		{"Mazda",		"RX-7 FD",			"PCMR",	"GGG-777",	42069,	true},
		{"Mazda",		"RX-7 FC",			"PCMR",	"HHH-888",	69420,	true},
		{"Subaru",		"Impreza STI",		"PCNR", "III-999",	41269,	false},
		{"Subaru",		"BRZ",				"PCMR",	"JJJ-000",	33869,	false},
		{"Toyota",		"Supra A70",		"PCMR", "KKK-111",	69420,	true},
		{"Toyota",		"Supra A80",		"PCMR", "LLL-222",	42069,	true},
		{"Toyota",		"Supra A90",		"PCMR", "MMM-333",	420,	true},
		{"Toyota",		"Corolla AE86",		"PCMR", "NNN-444",	8686,	true},
		{"Toyota",		"GT86",				"PCMR",	"OOO-555",	8669,	false},
	};

	char input[MAX] = "";
	char inputPrint[MAX] = "";
	char inputStatus[MAX] = "";

	printWelcome();
	while(1){
		getInput(input);

		if (strcmp(input, "HELP") == 0) { // HELP
			doHelp();
		} else if (strcmp(input, "PRINT") == 0) { // PRINT
			doPrint(inputPrint, rentals);
		} else if (strcmp(input, "STATUS") == 0) { // STATUS
			doStatus(inputStatus, rentals);
		} else if (strcmp(input, "QUIT") == 0) { // QUIT
			doExit();
			break;
		} else { // UNRECOGNIZED
			doUnrecognized();
		}
	}

	return 0;
}

void printList(char* str, struct Cars* vroom) {
	int i = 0;

	if (strcmp(str, "*") == 0) {
		for (i = 0; i < CARS; i++) {
			printf("Car number #%d\n", i+1);
			printf("Make:%*s\n", 20, vroom[i].make);
			printf("Model:%*s\n", 19, vroom[i].model);
			printf("Category:%*s\n", 16, vroom[i].category);
			printf("Plate:%*s\n", 19, vroom[i].plate);
			printf("Mileage:%*d\n", 17, vroom[i].mileage);
			printf("Status:%*s\n\n", 18, vroom[i].status ? "true" : "false");
		}
	} else {
		for (i = 0; i < CARS; i++) {
			if (strcmp(str, vroom[i].category) == 0) {
				printf("Car number #%d\n", i + 1);
				printf("Make:%*s\n", 20, vroom[i].make);
				printf("Model:%*s\n", 19, vroom[i].model);
				printf("Category:%*s\n", 16, vroom[i].category);
				printf("Plate:%*s\n", 19, vroom[i].plate);
				printf("Mileage:%*d\n", 17, vroom[i].mileage);
				printf("Status:%*s\n\n", 18, vroom[i].status ? "true" : "false");
			}
		}
	}
}

bool changeStatus(char* str, struct Cars* vroom) {
	int i = 0;
	bool found = false;

	for(i = 0; i < CARS; i++) {
		if (strcmp(str, vroom[i].plate) == 0) {
			found = true;
		}
	}
	return found;
}

void getInput(char* str) {
	printf("> ");
	fgets(str, MAX, stdin);
	parseInput(str);
}

void parseInput(char* str) {
	int i = 0;

	str[strcspn(str, "\n")] = '\0'; // Remove newline
	for (i = 0; i < strlen(str); i++) {
		str[i] = toupper(str[i]);
	}
}

void printWelcome() {
	printf("< Welcome!\n");
	printf("< Type %chelp%c for a list of available commands.\n", '"', '"');
}

void doHelp() {
	printf("< Available commands: help, print, status, quit\n");
}

void doPrint(char* str, struct Cars* vroom) {
	printf("< Enter license plate of the vehicle: \n");
	getInput(str);
	printList(str, vroom);
}

void doStatus(char* str, struct Cars* vroom) {
	printf("< Enter license plate of the vehicle: \n");
	getInput(str);
	bool result = changeStatus(str, vroom);
	if (result == true) {
		printf("< Status of the vehicle with license plate of %s changed!\n", str);
	} else {
		printf("< No vehicle with license plate of %s found!\n", str);
	}
}

void doUnrecognized() {
	printf("< Unrecognized command!\n");
	printf("< Type %chelp%c for a list of available commands.\n", '"', '"');
}

void doExit() {
	printf("< Exiting program!\n");
}