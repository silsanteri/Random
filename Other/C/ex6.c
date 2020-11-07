#pragma warning (disable:4996)
#include <stdio.h>
#define MAXLENGTH 100

void caesarCipher(char txt[], int const shft);
void makeUpper(char txt[]);

int main() {
    int shift = 0;
    char text[MAXLENGTH] = "";

    printf("Enter text to be encrypted:");
    fgets(text, MAXLENGTH, stdin);

    printf("Enter amount of shift used in the encryption:");
    scanf("%d", &shift);

    makeUpper(text);
    printf("Initial text: %s", text);

    caesarCipher(text, shift);
    printf("Encrypted text: %s", text);

    caesarCipher(text, shift * -1);
    printf("Decrypted text: %s", text);

    return 0;
}

void caesarCipher(char txt[], int const shft){
    int temp = 0;

    for (int i = 0; i < strlen(txt)-1; i++) {
        if (isalpha(txt[i])){
            temp = txt[i] + shft;

            // Check for bounds until the temp character is in bounds of uppercase alphabet ASCII value.
            while (temp < 65 || temp > 90){
                if (temp < 65) {
                    temp += 26;
                } else if (temp > 90) {
                    temp -= 26;
                }
            }
            txt[i] = temp;
        }
    }
}

void makeUpper(char txt[]) {
    for (int i = 0; i < strlen(txt); i++) {
        txt[i] = toupper(txt[i]);
    }
}