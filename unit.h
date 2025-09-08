//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
int FindMaxLessThenNumber(int _array[], int size, int _upNumber, int *flag);

int InputFromFile(int **array1, int **array2, int **array3, int *upNumber,
                  int *size1, int *size2, int *size3);

int InputFromConsole(int **array1, int **array2, int **array3, int *upNumber,
                     int *size1, int *size2, int *size3);

void OutMax(int max1, int max2, int max3, int flag1, int flag2, int flag3);
#endif //UNTITLED3_UNIT_H
