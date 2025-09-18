
#include <stdio.h>
#include <stdlib.h>
#include "transfer.h"
#include "unit.h"


//Каждая запись представляет собой 3 символа.
//поменять местами две записи и вывести содержимое
int main(void) {
    char filename[100];
    char bfilename[100] = "binarnichek.bin";

    int flag;

    FILE *fileText;
    FILE *fileBinary;

    printf("Enter filename: \n");
    scanf("%99s", filename);

    fileText = fopen(filename, "r");
    fileBinary = fopen(bfilename, "w+b");
    if (fileText == NULL || fileBinary == NULL) {
        printf("one or all files not exists");
    }
    else {
        transferFileToBFile(fileText, fileBinary, &flag);
        if (flag) {
            OutFile(fileBinary);
            ChageRecordPosition(fileBinary, 2, 3);
            printf("\n");
            OutFile(fileBinary);

            fclose(fileBinary);
            fclose(fileText);
        }
        else {
            printf("bad data in file");
        }
    }

    return 0;
}
