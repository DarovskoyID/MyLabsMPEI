#include "unit.h"
#include <stdio.h>
#include <stdlib.h>
void inputStringFromFile(char **inputString, int *len, FILE *file) {
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
void splitter(const char *input, char ***output, int lenStr, int lenwords) {
    int len = 0;
    *output = malloc(lenwords * sizeof(char *));
    int start = -1, j = 0;
    for (int i = 0; i < lenStr ; i++) {
        if (input[i] != ' ' && input[i] != '\0' && start == -1) start = i;
        if ((input[i] == ' ' || input[i] == '\0') && start != -1) {
            len = i - start;
            (*output)[j] = malloc(len + 1);
            for (int k = 0; k < len; k++) (*output)[j][k] = input[start + k];
            (*output)[j][len] = '\0';
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