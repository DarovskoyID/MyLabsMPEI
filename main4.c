#include <stdio.h>
#include "unitdyn.h"

int main(void) {

    int *array1;
    int *array2;
    int *array3;

    FILE *file;

    int size1, size2, size3, max1, max2, max3, upNumber;
    int flag1 = 0, flag2 = 0, flag3 = 0;

    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("file not exists");
    }
    else {
        inputArrayFromFile(&array1, &size1, file);
        inputArrayFromFile(&array2, &size2, file);
        inputArrayFromFile(&array3, &size3, file);

        fscanf(file, "%d", &upNumber);

        max1 = FindMaxFromIf(array1, size1, &flag1, upNumber);
        max2 = FindMaxFromIf(array2, size2, &flag2, upNumber);
        max3 = FindMaxFromIf(array3, size3, &flag3, upNumber);

        Out(max1, max2, max3, flag1, flag2, flag3);

        free(array1);
        free(array2);
        free(array3);
        fclose(file);
    }
    return 0;
}

