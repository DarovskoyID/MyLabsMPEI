
#include <stdio.h>
#include <stdlib.h>
#include "unit.h"

// Даны две матрицы разного размера. Для той из матриц,
// в которой есть элементы, равные 0, найти минимальный элемент в каждой строке.

int main(void) {

    int **matrix1;
    int **matrix2;

    int *array1;
    int *array2;

    int flag1, flag2;

    FILE *file;

    int sizeX1, sizeY1, sizeX2, sizeY2;

    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("file not exists");
    }
    else {
        inputMatrixFromFile(&matrix1, &sizeX1, &sizeY1, file);
        inputMatrixFromFile(&matrix2, &sizeX2, &sizeY2, file);
        flag1 = FindZero(matrix1, sizeX1, sizeY1);
        flag2 = FindZero(matrix2, sizeX2, sizeY2);
        if(flag1) {
            array1 = (int*) malloc((sizeY1) * sizeof(int));
            for (int i = 0; i < sizeY1; i++) {
                array1[i] = findMinArray(matrix1[i], sizeX1);
            }
        }

        if(flag2) {
            array2 = (int*) malloc((sizeY2) * sizeof(int));
            for (int i = 0; i < sizeY2; i++) {
                array2[i] = findMinArray(matrix2[i], sizeX2);
            }
        }

        if(flag1) {
            for (int i = 0; i < sizeY1; i++) {
                printf("%d ", array1[i]);
            }
        }
        printf("\n");
        if(flag2) {
            for (int i = 0; i < sizeY2; i++) {
                printf("%d ", array2[i]);
            }
        }

        if (flag1) free(array1);
        if (flag2) free(array2);
        free(matrix1);
        free(matrix2);
        fclose(file);
    }
    return 0;
}
