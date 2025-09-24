#include "unitdyn.h"

void FirstElemForMaxIf(int *array, int size, int *flag, int upNumber, int*elem) {
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


int FindMaxFromIf(int *array, int size, int upNumber, int firstmax) {
    int max;
    max = firstmax;
        for (int j = 0; j < size; j++) {
            if (max < array[j] && array[j] < upNumber) {
                max = array[j];
            }
        }
    return max;
}

void FindMin(int *array, int size, int *index, int *min) {
    *min = array[0];
    *index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < *min) {
            *min = array[i];
            *index = i;
        }
    }
    return;
}

void FindFirstMin(int *array, int size, int *index, int *elem, int *flag) {
    *flag = 0;
    *index = 0;
    while (!*flag && *index < size) {
        if(array[*index] > 0) {
            *elem = array[*index];
            *flag = 1;
        } else {
            (*index)++;
        }
    }
    return;
}


void FindPosMin(int *array, int size, int *index, int *min) {
    for (int i = 1; i < size; i++) {
        if (array[i] < *min && array[i] > 0) {
            *min = array[i];
            *index = i;
        }
    }
    return;
}

void swap(int **array1, int index1, int index2) {
    int temp = (*array1)[index1];
    (*array1)[index1] = (*array1)[index2];
    (*array1)[index2] = temp;
    return;
}

void inputArrayFromFile(int **array, int *size, FILE *file) {
    fscanf(file, "%d", size);
    *array = (int*) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        if (!feof(file)) fscanf(file, "%d", &(*array)[i]);
    }
    return;
}

void printArr(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}
