
#include <stdio.h>
#include <stdlib.h>
#include "transfer.h"
#include "unit.h"


//Каждая запись представляет собой 3 символа.
//поменять местами две записи и вывести содержимое
int main(void) {
    char filename[100];
    char bfilename[100] = "binarnichek";

    FILE *fileText;
    FILE *fileBinary;

    printf("Enter filename: ");
    scanf("%99s", filename);

    fileText = fopen(filename, "r");
    fileBinary = fopen(bfilename, "w+b");
    if (fileText == NULL || fileBinary == NULL) {
        printf("one or all files not exists");
    }
    else {
        transferFileToBFile(fileText, fileBinary);
        ChageRecordPosition(fileBinary, 2, 5);
        OutFile(fileBinary);

        fclose(fileBinary);
        fclose(fileText);
    }

    return 0;
}
