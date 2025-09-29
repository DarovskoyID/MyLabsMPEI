//
// Created by BottomWeb on 08.09.2025.
//


#include "unit.h"

void inputStringFromFile(char string[255], FILE *file) {
    if (fgets(string, sizeof(char) * 255, file) == NULL) printf("ERROR");
    return;
}
void splitter(const char inputString[255], char outputString[255][255], int i, int *j) {
    int m = 0;
    while(inputString[i] != '\0') {
        if (inputString[i] != ' ') {
            outputString[*j][m] = inputString[i];
            m++;
        }
        if (inputString[i] == ' ' && inputString[i+1] !=' ' || inputString[i+1] == '\0') {
            (*j)++;
            outputString[*j][m+1] = '\0';
            m = 0;
        }
        i++;
    }
    return;
}
int CalculateLen(char inputString[255]) {
    int i = 0;
    while (inputString[i] != '\0') i++;
    return i;
}
void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}
void swap(char a[255], char b[255]) {
    char temp[255];
    copyString(temp, a);
    copyString(a, b);
    copyString(b, temp);
    return;
}
int partition(char words[255][255], int low, int high) {
    int pivot = CalculateLen(words[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (CalculateLen(words[j]) <= pivot) {
            i++;
            swap(words[i], words[j]);
        }
    }
    swap(words[i + 1], words[high]);
    return i + 1;
}
void quickSort(char words[255][255], int low, int high) {
    if (low < high) {
        int pi = partition(words, low, high);
        quickSort(words, low, pi - 1);
        quickSort(words, pi + 1, high);
    }
}