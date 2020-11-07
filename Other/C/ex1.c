#include <stdio.h>

int main(){

    int total = 0, totalCount = 0, temp = 0;
    float final = 0;

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &temp);
        if (temp == 0) {
            if(total != 0){
                final = (float)total/(float)totalCount;
                printf("Average of numbers: %.2f", final);
                break;
            } else {
                // Fix for entering 0 on the first input.
                printf("Average of numbers: 0");
                break;
            }
        } else if (temp < 0){
            printf("Only positive numbers are allowed.\n");
        } else {
            total += temp;
            totalCount++;
        }
    }
    return 0;
}