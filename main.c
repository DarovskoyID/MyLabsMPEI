#include <stdio.h>
#include "unit.h"
int main(void) {
    FILE *file;
    char filename[100];
    char *string = NULL;
    char **words;
    int count = 0;
    size_t lenStr = 0;
    printf("Enter filename: ");
    scanf("%99s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("file not exists");
    } else {
       inputStringFromFile(&string, &lenStr, file);
        fclose(file);
        splitter(string, words, lenStr, &count);
        sortWordsByLen(words, count);
        for (int i = 0; i < count; i++) {
            printf("%s ", words[i]);
        }
    }

    return 0;
}