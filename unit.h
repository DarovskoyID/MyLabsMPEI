//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
#include <stdio.h>
#include <stdlib.h>

void findMinArray(int **mat, int **array, int sizeX, int sizeY);
void OutputArray(int *array, int size);
int FindZero(int **matrix, int sizeX, int sizeY);
void inputMatrixFromFile(int ***matrix, int *sizeX, int*sizeY, FILE *file);
int findMinMatrix(int **mat, int sizeX, int sizeY);
int findMaxMatrix(int **mat, int sizeX, int sizeY);
#endif //UNTITLED3_UNIT_H
