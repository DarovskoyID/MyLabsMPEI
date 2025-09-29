#include "transfer.h"
#include "record.h"

void transferFileToBFile(FILE *fileText, FILE *fileBinary, int *flag) {
    record rec;
    char buffer[100];
    *flag = 0;

    while (fgets(buffer, sizeof(buffer), fileText) != NULL) {
        int j = 0;
        int i = 0;
        while (buffer[i] != '\0' && j < 3) {
            if ((buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t') &&
                (buffer[i+1] == ' ' || buffer[i+1] == '\n' || buffer[i+1] == '\t' || buffer[i+1] == '\0') &&
                (buffer[i-1] == ' ' || buffer[i-1] == '\n' || buffer[i-1] == '\t' || buffer[i-1] == '\0')
                ) {
                rec[j] = buffer[i];
                j++;
            }
            i++;
        }

        if (j == 3) {
            fwrite(rec, sizeof(record), 1, fileBinary);
            *flag = 1;
        }
    }
    return;
}