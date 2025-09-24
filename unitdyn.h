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
void FindMin(int *array, int size, int *index, int *min);
void FindFirstMin(int *array, int size, int *index, int *elem, int *flag);
void FindPosMin(int *array, int size, int *index, int *min);
void swap(int **array1, int index1, int index2);
void printArr(int *array, int size);
#endif //UNITDYN_H
