//
// Created by Иван on 11.09.2025.
//

#ifndef UNITDYN_H
#define UNITDYN_H
#include <stdio.h>
#include <stdlib.h>

void FirstElemForMaxIf(int array[], int size, int *flag, int upNumber, int*elem);
int FindMaxFromIf(int *array, int size, int upNumber, int firstmax);
void inputArrayFromFile(int **array, int *size, FILE *file);

#endif //UNITDYN_H
