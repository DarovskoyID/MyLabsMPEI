#include "unit.h"
#include <stdio.h>
#include <stdlib.h>
void inputStringFromFile(char **inputString, size_t *len, FILE *file) {
    getline(inputString, len, file);
    return;
}
int countWords(const char *s) {
    int count = 0, inWord = 0;
    while (*s) {
        if (*s != ' ' && !inWord) { inWord = 1; count++; }
        else if (*s == ' ') inWord = 0;
        s++;
    }
    return count;
}
void splitter(const char *input, char **output, int lenStr, int *len) {
    int start = -1, j = 0;
    for (int i = 0; i < lenStr ; i++) {
        if (input[i] != ' ' && input[i] != '\0' && start == -1) start = i;
        if ((input[i] == ' ' || input[i] == '\0') && start != -1) {
            *len = i - start;
            output[j] = malloc(*len + 1);
            if (!output[j]) exit(1);
            for (int k = 0; k < *len; k++) output[j][k] = input[start + k];
            output[j][*len] = '\0';
            j++; start = -1;
        }
    }
    return;
}
int CalculateLen(char *inputString) {
    int i = 0;
    while (inputString[i] != '\0') i++;
    return i;
}
void copyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}
void sortWordsByLen(char **words, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (CalculateLen(words[j]) > CalculateLen(words[j+1])) {
                char *tmp = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp;
            }
    return;
}