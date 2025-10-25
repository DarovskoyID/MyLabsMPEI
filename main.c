#include <stdio.h>
#include "unit.h"
int main(void) {
    FILE *file; char filename[100], *string = NULL, **words; int lenStr = 0, lenWords = 0;
    scanf("%99s", filename); file = fopen(filename, "r");
    if (file == NULL) {printf("file not exists");}
    else {
        inputStringFromFile(&string, &lenStr, file);
        fclose(file);
        lenWords = countWords(string);
        splitter(string, &words, lenStr, lenWords);
        sortWordsByLen(words, lenWords);
        for (int i = 0; i < lenWords; i++) {
            printf("%s ", words[i]);
        }}
    return 0;}