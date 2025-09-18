#include <stdio.h>

void inputStringFromFile(char string[255], FILE *file) {
    if (fgets(string, sizeof(char) * 255, file) == NULL) {
        printf("ERROR");
        return;
    }
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
        i++;
    }
    return;
}

void splitter(const char inputString[255], char outputString[255][255], int *count) {
    int i = 0, j = 0, m = 0;
    *count = 0;

    while (inputString[i] != '\0') {
        if (inputString[i] != ' ') {
            outputString[j][m] = inputString[i];
            m++;
        } else {
            if (m > 0) {
                outputString[j][m] = '\0';
                j++;
                m = 0;
            }
        }
        i++;
    }

    if (m > 0) {
        outputString[j][m] = '\0';
        j++;
    }

    *count = j;
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
}

void swap(char a[255], char b[255]) {
    char temp[255];
    copyString(temp, a);
    copyString(a, b);
    copyString(b, temp);
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

int main(void) {
    FILE *file;
    char filename[100];
    char string[255];
    char words[255][255];
    int count;

    printf("Enter filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("file not exists");
        return 1;
    }

    inputStringFromFile(string, file);
    fclose(file);

    splitter(string, words, &count);
    quickSort(words, 0, count - 1);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
