//
// Created by BottomWeb on 08.09.2025.
//


#include "unit.h"

void FirstElemForMaxIf(int array[], int size, int *flag, int upNumber, int*elem) {
    int i = 0;

    while (!*flag && i < size) {
        if (array[i] < upNumber) {
            *elem = array[i];
            *flag = 1;
        } else {
            i++;
        }
    }
return;
}


int FindMaxFromIf(int array[], int size, int upNumber, int firstmax) {
    int max;
    max = firstmax;
        for (int j = 0; j < size; j++) {
            if (max < array[j] && array[j] < upNumber) {
                max = array[j];
            }
        }
    return max;
}

void inputArrayFromFile(int array[10], int *size, FILE *file) {
    fscanf(file, "%d", size);
    if (*size > 10) {
        printf("wrond length");
    }
    else {
        for (int i = 0; i < *size; i++){
            if (!feof(file)) fscanf(file, "%d", &array[i]);
        }
    }
    return;
}