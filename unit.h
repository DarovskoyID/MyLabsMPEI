//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
#include <stdio.h>

#define SIZEOFX 8
#define TYPEBIN u_int16_t
#define BITS (sizeof(TYPEBIN) * SIZEOFX)

unsigned int rotateRight(TYPEBIN x, int n);
unsigned int rotateLeft(TYPEBIN x, int n);
void PrintBinary(TYPEBIN x);
unsigned int binaryToDecimal(const char *s);

#endif //UNTITLED3_UNIT_H
