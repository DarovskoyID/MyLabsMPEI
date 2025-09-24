#include "unit.h"

int findMinInRow(int *row, int sizeX) {
    int min = row[0];
    for (int j = 1; j < sizeX; j++) {
        if (min > row[j]) {
            min = row[j];
        }
    }
    return min;
}

void findMinArray(int **mat, int **array, int sizeX, int sizeY) {
    *array = (int*) malloc(sizeY * sizeof(int));
    for (int i = 0; i < sizeY; i++) {
        (*array)[i] = findMinInRow(mat[i], sizeX);
    }
    return;
}


void OutputArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return;
}


int findZeroInRow(int *row, int sizeX) {
    int flag = 0;
    int j = 0;
    while (j < sizeX && !flag) {
        if (row[j] == 0) {
            flag = 1;
        } else {
            j++;
        }
    }
    return flag;
}

int FindZero(int **matrix, int sizeX, int sizeY) {
    int flag = 0;
    int i = 0;
    while (i < sizeY && !flag) {
        if (findZeroInRow(matrix[i], sizeX)) {
            flag = 1;
        } else {
            i++;
        }
    }
    return flag;
}


void inputString(int **array, int *sizeX, FILE *file) {
    *array = (int*) malloc((*sizeX) * sizeof(int));
    for (int j = 0; j < *sizeX; j++) {
        fscanf(file, "%d", &((*array)[j]));
    }
    return;
}

void inputMatrixFromFile(int ***matrix, int *sizeX, int *sizeY, FILE *file) {
    fscanf(file, "%d %d", sizeY, sizeX);
    *matrix = (int**) malloc((*sizeY) * sizeof(int*));

    for (int i = 0; i < *sizeY; i++) {
        inputString(&((*matrix)[i]), sizeX, file);
    }
    return;
}
