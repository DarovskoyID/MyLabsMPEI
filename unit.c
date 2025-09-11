//
// Created by BottomWeb on 08.09.2025.
//


#include "unit.h"

int FirstElemForMaxIf(int array[10], int size, int *flag, int upNumber) {
    int elem;
    int i = 0;

    while (!*flag && i < size) {
        if (array[i] < upNumber) {
            elem = array[i];
            *flag = 1;
        } else {
            i++;
        }
    }
    return elem;
}


int FindMaxFromIf(int array[10], int size, int *flag, int upNumber) {
    int max;
    max = FirstElemForMaxIf(array, size, flag, upNumber);
    if (*flag) {
        for (int j = 0; j < size; j++) {
            if (max < array[j] && array[j] < upNumber) {
                max = array[j];
            }
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
        for (int i = 0; i < *size; i++) fscanf(file, "%d", &array[i]);
    }
}

void Out(int max1, int max2, int max3, int flag1, int flag2, int flag3){
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
}