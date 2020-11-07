#pragma warning (disable:4996)
#include <stdio.h>

void multiplyMatrix(int res[3], int const vec[3], int const mat[3][3]);

int main() {

    int result[3] = { 0 }, vector[3] = { 0 }, matrix[3][3] = { 0 };
    int i, j;

    for (i = 0; i < 3; i++) {
        printf("Enter a value for vector[%d]:", i+1);
        scanf("%d", &vector[i]);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter a value for matrix[%d][%d]:", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Vector:\n%d %d %d\n\n", vector[0], vector[1], vector[2]);

    printf("Matrix:\n");
    for (i = 0; i < 3; i++) {
        printf("%d %d %d\n\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }

    multiplyMatrix(result, vector, matrix);
    printf("Result: %d %d %d", result[0], result[1], result[2]);

    return 0;
}

void multiplyMatrix(int res[3], int const vec[3], int const mat[3][3]){
    int i, j;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            res[j] += mat[j][i] * vec[i];
        }
    }
}