#include "unit.h"

int findMaxInRow(int *row, int sizeX) {
    int max = row[0];
    for (int j = 1; j < sizeX; j++) {
        if (max < row[j]) {
            max = row[j];
        }
    }
    return max;
}

int findMaxMatrix(int **mat, int sizeX, int sizeY) {
    int max = findMaxInRow(mat[0], sizeX);
    int temp;
    for (int i = 1; i < sizeY; i++) {
        temp = findMaxInRow(mat[i], sizeX);
        if (temp > max) {
            max = temp;
        }
    }
    return max;
}


int findMinInRow(int *row, int sizeX) {
    int min = row[0];
    for (int j = 1; j < sizeX; j++) {
        if (min > row[j]) {
            min = row[j];
        }
    }
    return min;
}

int findMinMatrix(int **mat, int sizeX, int sizeY) {
    int min = findMinInRow(mat[0], sizeX);
    int temp;
    for (int i = 1; i < sizeY; i++) {
        temp = findMinInRow(mat[i], sizeX);
        if (temp < min) {
            min = temp;
        }
    }
    return min;
}

void changeRow(int *row, int sizeX) {
    int left = 0, right = sizeX - 1;
    while (left < right) {
        while (left < sizeX && row[left] > 0) left++;
        while (right >= 0 && row[right] < 0) right--;
        if (left < right) {
            int tmp = row[left];
            row[left] = row[right];
            row[right] = tmp;
        }
    }
    return;
}

void change(int **mat, int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; i++) {
        changeRow(mat[i], sizeX);
    }
    return;
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
