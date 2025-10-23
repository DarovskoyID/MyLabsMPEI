//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_UNIT_H
#define UNTITLED3_UNIT_H
#include <stdio.h>


void inputStringFromFile(char **inputString, size_t *len, FILE *file);
void splitter(const char *input, char ***output, int lenStr, int lenwords);
int countWords(const char *s);
int CalculateLen(char *inputString);
void sortWordsByLen(char **words, int n);

#endif //UNTITLED3_UNIT_H