
#include <stdio.h>

void FirstElemForMaxIf(int array[], int size, int *flag, int*elem, int upNumber) {
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

void inputArrayFromConsole(int array[], int *size) {
    scanf("%d", size);
    if (*size > 10) {
        printf("wrond length");
    }
    else {
        for (int i = 0; i < *size; i++) scanf("%d", &array[i]);
    }
    return;
}
int main(void) {

    int array1[10];
    int array2[10];
    int array3[10];


    int size1, size2, size3, max1, max2, max3, fmax1, fmax2, fmax3, upNumber;
    int flag1 = 0, flag2 = 0, flag3 = 0;

    inputArrayFromConsole(array1, &size1);
    inputArrayFromConsole(array2, &size2);
    inputArrayFromConsole(array3, &size3);

    scanf("%d", &upNumber);

    FirstElemForMaxIf(array1, size1, &flag1, &fmax1, upNumber);
    FirstElemForMaxIf(array2, size2, &flag2, &fmax2, upNumber);
    FirstElemForMaxIf(array3, size3, &flag3, &fmax3, upNumber);

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
    return 0;
}

