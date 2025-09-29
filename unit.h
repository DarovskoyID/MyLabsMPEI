//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
#include <stdio.h>


void inputStringFromFile(char string[255], FILE *file);
void splitter(const char inputString[255], char outputString[255][255], int i, int *j);
int CalculateLen(char inputString[255]);
void copyString(char *dest, const char *src);
void swap(char a[255], char b[255]);
int partition(char words[255][255], int low, int high);
void quickSort(char words[255][255], int low, int high);

#endif //UNTITLED3_UNIT_H
