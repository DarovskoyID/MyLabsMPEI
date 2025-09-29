#include <stdio.h>
#include "unit.h"
int main(void) {
    FILE *file;
    char filename[100];
    char string[255];
    char words[255][255];
    int count = 0;
    printf("Enter filename: ");
    scanf("%99s", filename);
    file = fopen(filename, "r");
    file == NULL ? printf("file not exists") :
    inputStringFromFile(string, file);
    fclose(file);
    splitter(string, words, 0, &count);
    quickSort(words, 0, count - 1);
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    return 0;
}