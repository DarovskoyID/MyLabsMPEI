//
// Created by Иван on 11.09.2025.
//

#ifndef UNITDYN_H
#define UNITDYN_H
#include <stdio.h>
#include <stdlib.h>

int FirstElemForMaxIf(int *array, int size, int *flag, int upNumber);
int FindMaxFromIf(int *array, int size, int *flag, int upNumber);
void inputArrayFromFile(int **array, int *size, FILE *file);
void Out(int max1, int max2, int max3, int flag1, int flag2, int flag3);

#endif //UNITDYN_H
