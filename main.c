#include <stdio.h>
#include "unit.h"
int main(void) {
    unsigned int x, o1, o2;
    int n;
    char s[SIZEOFX];
    printf("input unsigned int: \n");
    scanf("%s", s);
    x = binaryToDecimal(s);
    printf("input int n: \n");
    scanf("%d", &n);
    o1 = rotateLeft(x, n);
    o2 = rotateRight(x, n);
    printf("HEX1: %X \n", o1);
    printf("HEX2: %X \n", o2);
    printf("DEC1: %u \n", o1);
    printf("DEC2: %u \n", o2);
    printf("Binary1: ");
    PrintBinary(o1);
    printf("\n");
    printf("Binary2: ");
    PrintBinary(o2);
    printf("\n");

    return 0;
}