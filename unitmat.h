//
// Created by Иван on 01.10.2025.
//

#ifndef UNITMAT_H
#define UNITMAT_H
#include <stdio.h>
#include <stdlib.h>
void OutputMat(int **mat, int sizeX, int sizeY);
void change(int **mat, int sizeX, int sizeY);
int findMinMatrix(int **mat, int sizeX, int sizeY);
int findMaxMatrix(int **mat, int sizeX, int sizeY);
void findMinArray(int **mat, int **array, int sizeX, int sizeY);
void OutputArray(int *array, int size);
int FindZero(int **matrix, int sizeX, int sizeY);
void inputMatrixFromFile(int ***matrix, int *sizeX, int *sizeY, FILE *file);
#endif //UNITMAT_H
