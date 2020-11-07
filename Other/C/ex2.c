#include <stdio.h>

int main(){

    float incomeArray[12];
    float incomeYearly = 0, incomeCalculated = 0;

    printf("Enter yearly gross income: ");
    scanf("%f", &incomeYearly);

    incomeCalculated = incomeYearly / 12.5;

    for(int x = 0; x <= 11; x++){
        if (x == 6){
            incomeArray[x] = incomeCalculated * 1.5;
        } else {
            incomeArray[x] = incomeCalculated;
        }
        printf("element[%2d] = %11.4f\n", x, incomeArray[x]);
    }

    printf("total       = %11.4f", incomeYearly);

    return 0;
}