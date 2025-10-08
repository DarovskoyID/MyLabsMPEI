#include "unit.h"
#include <stdio.h>
#include <stdlib.h>
unsigned int rotateRight(TYPEBIN x, int n) {
    return (x << n | x >> (BITS - n));
}
unsigned int rotateLeft(TYPEBIN x, int n) {
    return (x >> n | x << (BITS - n));
}
void PrintBinary(TYPEBIN x) {
    for (int i = BITS - 1; i >= 0; i--) {
        putchar((x & (1u << i)) ? '1' : '0');
    }
}
unsigned int binaryToDecimal(const char *s) {
    unsigned int result = 0;
    while (*s)
        result = result * 2 + (*s++ - '0');
    return result;
}