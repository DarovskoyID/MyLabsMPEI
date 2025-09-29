#include "unitdyn.h"

void printArrWithFunc(int *array, int size, int (*f)(int)) {
    for (int i = 0; i < size; i++) {
        printf("%d ", f ? f(array[i]) : array[i]);
    }
    printf("\n");
}

void FirstElemForMaxIf(int *array, int size, int *flag, int upNumber, int *elem, int (*f)(int)) {
    int i = 0;
    while (!*flag && i < size) {
        if (f(array[i]) < upNumber) {
            *elem = f(array[i]);
            *flag = 1;
        } else {
            i++;
        }
    }
}

int FindMaxFromIf(int *array, int size, int upNumber, int firstmax, int (*f)(int)) {
    int max = firstmax;
    for (int j = 0; j < size; j++) {
        int val = f(array[j]);
        if (max < val && val < upNumber) {
            max = val;
        }
    }
    return max;
}

int square(int x) {
    return x * x;
}

void inputArrayFromFile(int **array, int *size, FILE *file) {
    fscanf(file, "%d", size);
    *array = (int*) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        if (!feof(file)) fscanf(file, "%d", &(*array)[i]);
    }
    return;
}
