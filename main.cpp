#include <iostream>
#include "unit.h"
using namespace std;

int main() {
    FILE *file;
    char filename[100], *string = nullptr, **words;
    int lenStr = 0, lenWords = 0;

    cin >> filename;
    file = fopen(filename, "r");

    if (!file) {
        cout << "file not exists";
    } else {
        inputStringFromFile(&string, (size_t*)&lenStr, file);
        fclose(file);

        lenWords = countWords(string);
        splitter(string, &words, lenStr, lenWords);
        sortWordsByLen(words, lenWords);

        for (int i = 0; i < lenWords; i++)
            cout << words[i] << ' ';
    }

    return 0;
}
