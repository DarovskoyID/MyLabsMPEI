#include <stdio.h>
#include <stdlib.h>
#include "unitdyn.h"


//в том из 3 веткоров в котором меньше минимальный положительный поменять минимальный положительный и минимальный местами
int main(void) {

    int *array1;
    int *array2;
    int *array3;

    FILE *file1;
    FILE *file2;
    FILE *file3;

    int size1, size2, size3, max1, max2, max3, fmax1, fmax2, fmax3, upNumber, indexmin1, indexmin2, indexmin3,
    indexminpos1, indexminpos2, indexminpos3,
    min1, min2, min3, minpos1, minpos2, minpos3;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    int flag11 = 0, flag21 = 0, flag31 = 0;

    char filename1[100];
    char filename2[100];
    char filename3[100];

    printf("Enter filename: ");
    scanf("%99s", filename1);
    scanf("%99s", filename2);
    scanf("%99s", filename3);

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    file3 = fopen(filename3, "r");
    if (file1 == NULL && file2 == NULL && file3 == NULL) {
        printf("file not exists");
    }
    else {
        inputArrayFromFile(&array1, &size1, file1);
        inputArrayFromFile(&array2, &size2, file2);
        inputArrayFromFile(&array3, &size3, file3);

        scanf("%d", &upNumber);

        printArr(array1, size1);
        printArr(array2, size2);
        printArr(array3, size3);

        FindFirstMin(array1, size1, &indexminpos1, &minpos1, &flag11);
        FindFirstMin(array2, size2, &indexminpos2, &minpos2, &flag21);
        FindFirstMin(array3, size3, &indexminpos3, &minpos3, &flag31);

        if (flag11) {
            FindPosMin(array1, size1, &indexminpos1, &minpos1);
        }
        if (flag21) {
            FindPosMin(array2, size2, &indexminpos2, &minpos2);
        }
        if (flag31) {
            FindPosMin(array3, size3, &indexminpos3, &minpos3);
        }

        if (flag11 && flag21 && flag31) {
            if (minpos1 <= minpos2 && minpos1 <= minpos3) {
                FindMin(array1, size1, &indexmin1, &min1);
                swap(&array1, indexminpos1, indexmin1);
            }
            else if (minpos2 <= minpos1 && minpos2 <= minpos3) {
                FindMin(array2, size2, &indexmin2, &min2);
                swap(&array2, indexminpos2, indexmin2);
            } else {
                FindMin(array3, size3, &indexmin3, &min3);
                swap(&array3, indexminpos3, indexmin3);
            }
        } else if (flag11 && flag21) {
            if (minpos1 <= minpos2) {
                FindMin(array1, size1, &indexmin1, &min1);
                swap(&array1, indexminpos1, indexmin1);
            } else {
                FindMin(array2, size2, &indexmin2, &min2);
                swap(&array2, indexminpos2, indexmin2);
            }
        } else if (flag21 && flag31) {
            if (minpos2 <= minpos3) {
                FindMin(array2, size2, &indexmin2, &min2);
                swap(&array2, indexminpos2, indexmin2);
            } else {
                FindMin(array3, size3, &indexmin3, &min3);
                swap(&array3, indexminpos3, indexmin3);
            }
        } else if (flag11 && flag31) {
            if (minpos1 <= minpos3) {
                FindMin(array1, size1, &indexmin1, &min1);
                swap(&array1, indexminpos1, indexmin1);
            } else {
                FindMin(array3, size3, &indexmin3, &min3);
                swap(&array3, indexminpos3, indexmin3);
            }
        } else if (flag11) {
            FindMin(array1, size1, &indexmin1, &min1);
            swap(&array1, indexminpos1, indexmin1);
        } else if (flag21) {
            FindMin(array2, size2, &indexmin2, &min2);
            swap(&array2, indexminpos2, indexmin2);
        } else if (flag31) {
            FindMin(array3, size3, &indexmin3, &min3);
            swap(&array3, indexminpos3, indexmin3);
        }


        printArr(array1, size1);
        printArr(array2, size2);
        printArr(array3, size3);



        FirstElemForMaxIf(array1, size1, &flag1, upNumber, &fmax1);
        FirstElemForMaxIf(array2, size2, &flag2, upNumber, &fmax2);
        FirstElemForMaxIf(array3, size3, &flag3, upNumber, &fmax3);

        if(flag1) max1 = FindMaxFromIf(array1, size1, upNumber, fmax1);
        if(flag2) max2 = FindMaxFromIf(array2, size2, upNumber, fmax2);
        if(flag3) max3 = FindMaxFromIf(array3, size3, upNumber, fmax3);

        if (flag1 && flag2 && flag3) {
            if (max1 == max2 && max2 == max3) {
                printf("All maximum are %d", max1);
            } else if (max1 == max2 && max1 < max3) {
                printf("Maximum1 and maximum2 are %d", max1);
            } else if (max1 == max3 && max1 < max2) {
                printf("Maximum1 and maximum3 are %d", max1);
            } else if (max2 == max3 && max2 < max1) {
                printf("Maximum2 and maximum3 are %d", max2);
            } else if (max1 < max2 && max1 < max3) {
                printf("Maximum1 are %d", max1);
            } else if (max2 < max1 && max2 < max3) {
                printf("Maximum2 are %d", max2);
            } else if (max3 < max1 && max3 < max2) {
                printf("Maximum3 are %d", max3);
            }
        } else if (flag1 && flag2) {
            if (max1 == max2) {
                printf("Maximum1 and maximum2 are %d", max1);
            } else if (max1 < max2) {
                printf("Maximum1 are %d", max1);
            } else {
                printf("Maximum2 are %d", max2);
            }
        } else if (flag1 && flag3) {
            if (max1 == max3) {
                printf("Maximum1 and maximum3 are %d", max1);
            } else if (max1 < max3) {
                printf("Maximum1 are %d", max1);
            } else {
                printf("Maximum3 are %d", max3);
            }
        } else if (flag2 && flag3) {
            if (max2 == max3) {
                printf("Maximum2 and maximum3 are %d", max2);
            } else if (max2 < max3) {
                printf("Maximum2 are %d", max2);
            } else {
                printf("Maximum3 are %d", max3);
            }
        } else if (flag1) {
            printf("Maximum1 are %d", max1);
        } else if (flag2) {
            printf("Maximum2 are %d", max2);
        } else if (flag3) {
            printf("Maximum3 are %d", max3);
        }

        free(array1);
        free(array2);
        free(array3);
        fclose(file1);
        fclose(file2);
        fclose(file3);
    }
    return 0;
}

