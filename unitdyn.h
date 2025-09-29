//
// Created by Иван on 11.09.2025.
//

#ifndef UNITDYN_H
#define UNITDYN_H
#include <stdio.h>
#include <stdlib.h>

void inputArrayFromFile(int **array, int *size, FILE *file);
int FindMaxFromIf(int *array, int size, int upNumber, int firstmax, int (*f)(int));
void FirstElemForMaxIf(int *array, int size, int *flag, int upNumber, int *elem, int (*f)(int));
int square(int x);
void printArrWithFunc(int *array, int size, int (*f)(int));
#endif //UNITDYN_H
