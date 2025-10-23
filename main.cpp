#include <iostream>
#include "unit_dll_M.h"
using namespace std;

int main() {
    FILE *file;
    char filename[100], *string = nullptr, **words;
    int lenStr = 0, lenWords = 0;

    scanf("%s", filename);
    file = fopen(filename, "r");

    if (!file) {
        printf("file not exists");
    } else {
        inputStringFromFile(&string, (size_t*)&lenStr, file);
        fclose(file);

        lenWords = countWords(string);
        splitter(string, &words, lenStr, lenWords);
        sortWordsByLen(words, lenWords);

        for (int i = 0; i < lenWords; i++)
            printf("%s ", words[i]);
        printf("\n");
    }

    return 0;
}
