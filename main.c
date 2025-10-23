#include <stdio.h>
#include "unit.h"

//с к позиции инвертировать н бит
int main(void) {
    unsigned int x, o1, o2, o3;
    int n, k;
    char s[SIZEOFX];
    printf("input unsigned int: \n");
    scanf("%s", s);
    x = binaryToDecimal(s);
    printf("input int n: \n");
    scanf("%d", &n);
    printf("input int k: \n");
    scanf("%d", &k);
    o1 = rotateLeft(x, n);
    o2 = rotateRight(x, n);
    o3 = invertBits(x, k, n);
    printf("HEX1: %X \n", o1);
    printf("HEX2: %X \n", o2);
    printf("HEX3: %X \n", o3);
    printf("DEC1: %u \n", o1);
    printf("DEC2: %u \n", o2);
    printf("DEC3: %u \n", o3);
    printf("OCT1: %o \n", o1);
    printf("OCT2: %o \n", o2);
    printf("OCT3: %o \n", o3);
    printf("Binary1: ");
    PrintBinary(o1);
    printf("\n");
    printf("Binary2: ");
    PrintBinary(o2);
    printf("\n");
    printf("Binary3: ");
    PrintBinary(o3);
    printf("\n");

    return 0;
}