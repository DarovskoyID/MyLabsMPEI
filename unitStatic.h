//
// Created by Иван on 20.09.2025.
//

#ifndef UNITSTATIC_H
#define UNITSTATIC_H
#include <stdio.h>
#define MAXX 10
#define MAXY 10

void findMinArray(int mat[MAXY][MAXX], int array[], int sizeX, int sizeY);
void OutputArray(int array[], int size);
int FindZero(int matrix[MAXY][MAXX], int sizeX, int sizeY);
void inputMatrixFromFile(int matrix[MAXY][MAXX], int *sizeX, int*sizeY, FILE *file);
#endif //UNITSTATIC_H
