#include <stdio.h>
#include <stdlib.h>
#include "unitdyn.h"
#include <math.h>
int mod10(int x) {
    return x % 10;
}
//require sinx cosx tgx e^x lnx x%10 abs square userFunc
int main(void) {
    int *array1, *array2, *array3;
    int size1, size2, size3;
    FILE *file1, *file2, *file3;

    char filename1[100], filename2[100], filename3[100];
    printf("Enter 3 filenames: ");
    scanf("%99s %99s %99s", filename1, filename2, filename3);

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    file3 = fopen(filename3, "r");

    if (!file1 || !file2 || !file3) {
        printf("Error: file not exists\n");
        return 1;
    }

    inputArrayFromFile(&array1, &size1, file1);
    inputArrayFromFile(&array2, &size2, file2);
    inputArrayFromFile(&array3, &size3, file3);

    int upNumber;
    printf("Enter upper bound: ");
    scanf("%d", &upNumber);

    int (*f1)(int) = abs;
    int (*f2)(int) = square;

    int (*f3)(int) = mod10;

    printf("Array1: ");
    printArrWithFunc(array1, size1, NULL);

    printf("Array1 with abs: ");
    printArrWithFunc(array1, size1, f1);

    printf("Array2 with square: ");
    printArrWithFunc(array2, size2, f2);

    printf("Array3 with lambda (x %% 10): ");
    printArrWithFunc(array3, size3, f3);

    int flag1 = 0, fmax1;
    int flag2 = 0, fmax2;
    int flag3 = 0, fmax3;

    FirstElemForMaxIf(array1, size1, &flag1, upNumber, &fmax1, f1);
    FirstElemForMaxIf(array2, size2, &flag2, upNumber, &fmax2, f2);
    FirstElemForMaxIf(array3, size3, &flag3, upNumber, &fmax3, f3);

    if (flag1) {
        int max1 = FindMaxFromIf(array1, size1, upNumber, fmax1, f1);
        printf("Max1 (with abs) = %d\n", max1);
    }
    if (flag2) {
        int max2 = FindMaxFromIf(array2, size2, upNumber, fmax2, f2);
        printf("Max2 (with square) = %d\n", max2);
    }
    if (flag3) {
        int max3 = FindMaxFromIf(array3, size3, upNumber, fmax3, f3);
        printf("Max3 (with lambda) = %d\n", max3);
    }

    free(array1);
    free(array2);
    free(array3);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}


