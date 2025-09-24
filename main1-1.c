
#include <stdio.h>

int main(void) {

    int array1[10];
    int array2[10];
    int array3[10];


    int size1, size2, size3, max1, max2, max3, upNumber;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    int elem1, elem2, elem3;
    int i = 0;

    scanf("%d", &size1);
    if (size1 > 10) {
        printf("wrond length");
    }
    else {
        for (int i = 0; i < size1; i++) scanf("%d", &array1[i]);
    }
    scanf("%d", &size2);
    if (size2 > 10) {
        printf("wrond length");
    }
    else {
        for (int i = 0; i < size2; i++) scanf("%d", &array2[i]);
    }
    scanf("%d", &size3);
    if (size3 > 10) {
        printf("wrond length");
    }
    else {
        for (int i = 0; i < size3; i++) scanf("%d", &array3[i]);
    }

    scanf("%d", &upNumber);



    while (!flag1 && i < size1) {
        if (array1[i] < upNumber) {
            elem1 = array1[i];
            flag1 = 1;
        } else {
            i++;
        }
    }


    if (flag1) {
        max1 = elem1;
        for (int j = 0; j < size1; j++) {
            if (max1 < array1[j] && array1[j] < upNumber) {
                max1 = array1[j];
            }
        }
    }

    while (!flag2 && i < size2) {
        if (array2[i] < upNumber) {
            elem2 = array2[i];
            flag2 = 1;
        } else {
            i++;
        }
    }


    if (flag2) {
        max2 = elem2;
        for (int j = 0; j < size2; j++) {
            if (max2 < array2[j] && array2[j] < upNumber) {
                max2 = array2[j];
            }
        }
    }

    while (!flag3 && i < size3) {
        if (array3[i] < upNumber) {
            elem3 = array3[i];
            flag3 = 1;
        } else {
            i++;
        }
    }


    if (flag3) {
        max3 = elem3;
        for (int j = 0; j < size3; j++) {
            if (max3 < array3[j] && array3[j] < upNumber) {
                max3 = array3[j];
            }
        }
    }

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

