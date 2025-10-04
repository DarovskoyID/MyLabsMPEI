//
// Created by Иван on 20.09.2025.
//

#ifndef UNITSTATIC_H
#define UNITSTATIC_H
#include <stdio.h>
#include <stdlib.h>
#define MAXX 10
#define MAXY 10

int findMinInRow(int row[], int sizeX);
void findMinArray(int mat[][MAXX], int array[], int sizeX, int sizeY);
void OutputArray(int array[], int size);
int findZeroInRow(int row[], int sizeX);
int FindZero(int matrix[][MAXX], int sizeX, int sizeY);
void inputString(int array[], int *sizeX, FILE *file);
void inputMatrixFromFile(int matrix[][MAXX], int *sizeX, int *sizeY, FILE *file);

void findMinArray(int mat[MAXY][MAXX], int array[], int sizeX, int sizeY);
void OutputArray(int array[], int size);
int FindZero(int matrix[MAXY][MAXX], int sizeX, int sizeY);
void inputMatrixFromFile(int matrix[MAXY][MAXX], int *sizeX, int*sizeY, FILE *file);
#endif //UNITSTATIC_H
