//Сформировать строку из слов исходной строки
//в порядке увеличения количества символов в слове.
#include <stdio.h>

void inputStringFromFile(char *string[255], FILE *file) {
    if (fgets(string,sizeof(string) , file) == NULL) {
        printf("ERROR");
    }
}

void splitter(const char inputString[255], char outputString[255][255], int i, int j, int m) {
    if (inputString[i] == '\0') {
        outputString[j][m] = '\0';
        return;
    }

    if (inputString[i] != ' ') {
        outputString[j][m] = inputString[i];
        splitter(inputString, outputString, i + 1, j, m + 1);
    } else {
        outputString[j][m] = '\0';
        while (inputString[i] == ' ') i++; // убираем лишние пробелы
        splitter(inputString, outputString, i, j + 1, 0);
    }
}

int main(void) {

    FILE *file;

    char filename[100];
    char string[255];
    char words[255][255];

    printf("Enter filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("file not exists");
    }

    inputStringFromFile(string, file);
    splitter(string, words, 0, 0, 0);
    return 0;
}