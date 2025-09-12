#include "unit.h"

int findMinArray(int *array, int sizeX) {
    int min = array[0];
    for (int i = 1; i < sizeX; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

int FindZero(int **matrix, int sizeX, int sizeY) {
    int i = 0;
    int j = 0;
    int flag = 0;
    while (i < sizeY && !flag) {
        while (j < sizeX && !flag) {
            if (matrix[i][j] == 0) {
                flag = 1;
            } else {
                j++;
            }
        }
        if (!flag) {
          i++;
        }

    }
    return flag;
}

void inputMatrixFromFile(int ***matrix, int *sizeX, int*sizeY, FILE *file) {
    fscanf(file, "%d %d", sizeY, sizeX);

    *matrix = (int**) malloc((*sizeY) * sizeof(int*));
    for (int i = 0; i < *sizeY; i++) {
        (*matrix)[i] = (int*) malloc((*sizeX) * sizeof(int));
    }

    for (int i = 0; i < *sizeY; i++) {
        for (int j = 0; j < *sizeX; j++) {
            fscanf(file, "%d", &(*matrix)[i][j]);
        }
    }
}