//
// Created by Иван on 01.10.2025.
//

#ifndef STAT_H
#define STAT_H
#include <stdio.h>
#define MAXX 10

void findMinArray(int mat[][MAXX], int array[], int sizeX, int sizeY);
void OutputArray(int array[], int size);
int FindZero(int matrix[][MAXX], int sizeX, int sizeY);
void inputMatrixFromFile(int matrix[][MAXX], int *sizeX, int *sizeY, FILE *file);
#endif //STAT_H
