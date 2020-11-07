#include <stdio.h>

float arrayAverage(int arr[], int arrSize);
int getStudents();
int getGrade(int studentNumber);

int main(){

    int grades[100] = { 0 };
    int tempGrade = 0;
    int students = getStudents();

    for(int x = 0; students > x; x++){
        grades[x] = getGrade(45000+x+1);
    }

    printf("Course average of %d students: %.2f", students, arrayAverage(grades, students));

    return 0;
}

// arrayAverage
float arrayAverage(int arr[], int arrSize){
    float final = 0;

    for(int x = 0; arrSize > x; x++){
        final += (float)arr[x];
    }

    final /= arrSize;

    return final;
}

// getStudents
int getStudents(){
    int students = 0;

    while(students > 100 || students < 1){
        printf("Enter the amount of students between 1-100: ");
        scanf("%d", &students);
    }

    return students;
}

// getGrade
int getGrade(int studentNumber){
    int tempGrade = 0;

    printf("Enter a grade for the student number %d: ", studentNumber);
    scanf("%d", &tempGrade);

    while(tempGrade > 5 || tempGrade < 0){
            printf("Only grades between 0-5 are allowed!\n");
            printf("Enter a grade for the student number %d: ", studentNumber);
            scanf("%d", &tempGrade);
    }

    return tempGrade;
}