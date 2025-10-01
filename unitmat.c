//
// Created by Иван on 01.10.2025.
//
#include "unitmat.h"
#include <stdio.h>


int findMaxMatrix(int **mat, int sizeX, int sizeY) {
    int max = mat[0][0];
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (mat[i][j] > max) {
                max = mat[i][j];
            }
        }
    }
    return max;
}

int findMinMatrix(int **mat, int sizeX, int sizeY) {
    int min = mat[0][0];
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
    }
    return min;
}

void change(int **mat, int sizeX, int sizeY) {
    int half = sizeY / 2;

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (mat[i][j] < 0) {
                int found = 0;
                for (int k = half; k < sizeY && !found; k++) {
                    for (int l = 0; l < sizeX && !found; l++) {
                        if (mat[k][l] > 0) {
                            int tmp = mat[i][j];
                            mat[i][j] = mat[k][l];
                            mat[k][l] = tmp;
                            found = 1;
                        }
                    }
                }
            }
        }
    }

    return;
}

void OutputMat(int **mat, int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}



void findMinArray(int **mat, int **array, int sizeX, int sizeY) {
    *array = (int*) malloc(sizeY * sizeof(int));
    for (int i = 0; i < sizeY; i++) {
        int min = mat[i][0];
        for (int j = 1; j < sizeX; j++) {
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
        (*array)[i] = min;
    }
    return;
}



void OutputArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return;
}


int FindZero(int **matrix, int sizeX, int sizeY) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < sizeY && !flag) {
        j = 0;
        while (j < sizeX && !flag) {
            if (matrix[i][j] == 0) {
                flag = 1;
            } else {
                j++;
            }
        }
        if(!flag) {
            i++;
        }
    }
    return flag;
}


void inputMatrixFromFile(int ***matrix, int *sizeX, int *sizeY, FILE *file) {
    fscanf(file, "%d %d", sizeY, sizeX);
    *matrix = (int**) malloc((*sizeY) * sizeof(int*));

    for (int i = 0; i < *sizeY; i++) {
        (*matrix)[i] = (int*) malloc((*sizeX) * sizeof(int)); // исправлено
        for (int j = 0; j < *sizeX; j++) {
            fscanf(file, "%d", &((*matrix)[i][j])); // исправлено
        }
    }
    return;
}

