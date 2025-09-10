
#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

int FindMaxLessThenNumber(int _array[], int size, int _upNumber, int *flag);

int InputFromFile(int **array1, int **array2, int **array3, int *upNumber,
                  int *size1, int *size2, int *size3);

int InputFromConsole(int **array1, int **array2, int **array3, int *upNumber,
                     int *size1, int *size2, int *size3);

void OutMax(int max1, int max2, int max3, int flag1, int flag2, int flag3);

int main(void) {

    int *array1;
    int *array2;
    int *array3;

    DynamicArray arr;
    initArray(&arr, 2);
    pushBack(&arr, 10);
    freeArray(&arr);

    int size1, size2, size3;
    int flag1 = 0, flag2 = 0, flag3 = 0;

    int upNumber;

    int max1 = 0, max2 = 0, max3 = 0, temp;

    temp = InputFromFile(&array1, &array2, &array3, &upNumber, &size1, &size2, &size3);

    if (temp == 0) {
        max1 = FindMaxLessThenNumber(array1, size1, upNumber, &flag1);
        max2 = FindMaxLessThenNumber(array2, size2, upNumber, &flag2);
        max3 = FindMaxLessThenNumber(array3, size3, upNumber, &flag3);

        OutMax(max1, max2, max3, flag1, flag2, flag3);
    }
    return 0;
}

int InputFromFile(int **array1, int **array2, int **array3, int *upNumber,
                  int *size1, int *size2, int *size3) {
    char fileName[256];
    printf("Input filename \n");
    scanf("%255s", fileName);

    FILE *inputfile = fopen(fileName, "r");
    if (inputfile == NULL) {
        printf("file not found \n");
        return -1;
    }

    fscanf(inputfile, "%d", size1);
    fscanf(inputfile, "%d", size2);
    fscanf(inputfile, "%d", size3);

    *array1 = malloc(*size1 * sizeof(int));
    *array2 = malloc(*size2 * sizeof(int));
    *array3 = malloc(*size3 * sizeof(int));

    for (int i = 0; i < *size1; i++) fscanf(inputfile, "%d", &(*array1)[i]);
    for (int i = 0; i < *size2; i++) fscanf(inputfile, "%d", &(*array2)[i]);
    for (int i = 0; i < *size3; i++) fscanf(inputfile, "%d", &(*array3)[i]);

    fscanf(inputfile, "%d", upNumber);

    fclose(inputfile);
    return 0;
}

int InputFromConsole(int **array1, int **array2, int **array3, int *upNumber,
                     int *size1, int *size2, int *size3) {
    scanf( "%d", size1);
    scanf("%d", size2);
    scanf( "%d", size3);

    *array1 = malloc(*size1 * sizeof(int));
    *array2 = malloc(*size2 * sizeof(int));
    *array3 = malloc(*size3 * sizeof(int));

    for (int i = 0; i < *size1; i++) scanf( "%d", &(*array1)[i]);
    for (int i = 0; i < *size2; i++) scanf("%d", &(*array2)[i]);
    for (int i = 0; i < *size3; i++) scanf( "%d", &(*array3)[i]);

    scanf( "%d", upNumber);
    return 0;
}

int FindMaxLessThenNumber(int _array[], int size, int _upNumber, int *flag) {
    int i = {0};
    int max = 0;
    while (!*flag && i < size) {
        if (_array[i] < _upNumber) {
            max = _array[i];
            *flag = 1;
        } else {
            i++;
        }
    }

    if (*flag) {
        for (int j = i + 1; j < size; j++) {
            if (max < _array[j] && _array[j] < _upNumber) {
                max = _array[j];
            }
        }
    }

    return max;
}

void OutMax(int max1, int max2, int max3, int flag1, int flag2, int flag3) {
    if (flag1){
        if (flag2){
            if(flag3){
                if (max1 == max2 && max2 == max3) printf("All maximum are %d", max1);
                if (max1 == max2 && max1 < max3) printf("Maximum1 and maximum2 are %d", max1);
                if (max1 == max3 && max1 < max2) printf("Maximum1 and maximum3 are %d", max1);
                if (max2 == max3 && max2 < max1) printf("Maximum2 and maximum3 are %d", max2);

                if (max1 < max2 && max1 < max3) printf("Maximum1 are %d", max1);
                if (max2 < max1 && max2 < max3) printf("Maximum2 are %d", max2);
                if (max3 < max1 && max3 < max2) printf("Maximum3 are %d", max3);
            } else {
                if (max1 == max2) printf("Maximum1 and maximum2 are %d", max1);
                if (max1 < max2) printf("Maximum1 are %d", max1);
                if (max1 > max2) printf("Maximum2 are %d", max2);
            }
        } else {
            if(flag3) {
                if (max1 == max3) printf("Maximum1 and maximum3 are %d", max1);
                if (max1 < max3) printf("Maximum1 are %d", max1);
                if (max1 > max3) printf("Maximum3 are %d", max3);
            } else {
                printf("Maximum1 are %d", max1);
            }
        }
    } else {
        if (flag2){
            if (flag3){
                if (max3 == max2) printf("Maximum3 and maximum2 are %d", max3);
                if (max3 < max2) printf("Maximum3 are %d", max3);
                if (max3 > max2) printf("Maximum2 are %d", max2);
            } else {
                printf("Maximum2 are %d", max2);
            }
        } else {
            if (flag3){
                printf("Maximum3 are %d", max3);
            }
        }

    }

}