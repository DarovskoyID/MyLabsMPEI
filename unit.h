//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
#include <stdio.h>

#define SIZEOFX 8
#define BITS (sizeof(unsigned int) * SIZEOFX)

unsigned int rotateRight(unsigned int x, int n);
unsigned int rotateLeft(unsigned int x, int n);
void PrintBinary(unsigned int x);
unsigned int binaryToDecimal(const char *s);

#endif //UNTITLED3_UNIT_H
