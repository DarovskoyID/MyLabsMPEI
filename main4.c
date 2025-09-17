
#include <stdio.h>
#include "unit.h"

// Даны две матрицы разного размера. Для той из матриц,
// в которой есть элементы, равные 0, найти минимальный элемент в каждой строке.

int main(void) {

    int **matrix1;
    int **matrix2;

    int *array1;
    int *array2;

    int flag1, flag2;

    FILE *file1;
    FILE *file2;

    int sizeX1, sizeY1, sizeX2, sizeY2;

    char filename1[100];
    char filename2[100];

    printf("Enter filename: ");
    scanf("%99s", filename1);
    scanf("%99s", filename2);

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    if (file1 == NULL && file2 == NULL) {
        printf("file not exists");
    }
    else {
        inputMatrixFromFile(&matrix1, &sizeX1, &sizeY1, file1);
        inputMatrixFromFile(&matrix2, &sizeX2, &sizeY2, file2);
        flag1 = FindZero(matrix1, sizeX1, sizeY1);
        flag2 = FindZero(matrix2, sizeX2, sizeY2);
        if(flag1) {
            findMinArray(matrix1, &array1, sizeX1, sizeY1);
        }

        if(flag2) {
            findMinArray(matrix2, &array2, sizeX2, sizeY2);
        }

        if(flag1) {
            OutputArray(array1, sizeY1);
        }
        printf("\n");
        if(flag2) {
            OutputArray(array2, sizeY2);
        }

        if (flag1) free(array1);
        if (flag2) free(array2);
        free(matrix1);
        free(matrix2);
        fclose(file1);
        fclose(file2);
    }
    return 0;
}
