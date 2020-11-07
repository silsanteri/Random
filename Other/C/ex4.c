#include <stdio.h>

int timeCheck(int hour, int minute);
void finalTime(int h1, int m1, int h2, int m2);

int main(){
    int currentHour = 0, currentMin = 0, sleepHour = 0, sleepMin = 0;

    do{
        printf("Enter current time (hh:mm):");
        scanf("%d:%d", &currentHour, &currentMin);
    }while(timeCheck(currentHour, currentMin) == 0);

    do{
        printf("How long do you want to sleep (h:mm):");
        scanf("%d:%d", &sleepHour, &sleepMin);
    }while(timeCheck(sleepHour, sleepMin) == 0);

    finalTime(currentHour, currentMin, sleepHour, sleepMin);

    return 0;
}

int timeCheck(int hour, int minute){
    if(hour > 24 || hour < 0 || minute > 60 || minute < 0) {
        return 0;
    } else {
        return 1;
    }
}

void finalTime (int h1, int m1, int h2, int m2){
    int h3 = h1 + h2;
    int m3 = m1 + m2;

    if(m3 >= 60){
        m3 -= 60;
        h3++;
    }

    if(h3 >= 24){
        h3 -= 24;
    }

    if(m3 == 0){
        // A fix to display xx:00 instead of xx:0 if minutes are 0
        printf("If you go to bed now you must wake up at %d:00", h3);
    } else {
        printf("If you go to bed now you must wake up at %d:%d", h3, m3);
    }
}