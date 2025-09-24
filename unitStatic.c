//
// Created by Иван on 20.09.2025.
//
#include "unitStatic.h"

void findMinArray(int mat[MAXY][MAXX], int array[], int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; i++) {
        int min = mat[i][0];
        for (int j = 1; j < sizeX; j++) {
            if (min > mat[i][j]) {
                min = mat[i][j];
            }
        }
        array[i] = min;
    }
    return;
}

void OutputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return;
}


int FindZero(int matrix[][MAXX], int sizeX, int sizeY) {
    int i = 0;
    int j = 0;
    int flag = 0;
    while (i < sizeY && !flag) {
        j = 0;
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

void inputMatrixFromFile(int matrix[MAXY][MAXX], int *sizeX, int *sizeY, FILE *file) {
    fscanf(file, "%d %d", sizeY, sizeX);
    for (int i = 0; i < *sizeY; i++) {
        for (int j = 0; j < *sizeX; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    return;
}