#include "transfer.h"
#include "record.h"

void transferFileToBFile(FILE *fileText, FILE *fileBinary, int *flag) {
    record rec;
    char buffer[100];
    *flag = 0;

    while (fgets(buffer, sizeof(buffer), fileText) != NULL) {
        int j = 0;
        for (int i = 0; buffer[i] != '\0' && j < 3; i++) {
            if ((buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= 'a' && buffer[i] <= 'z')){
                rec[j] = buffer[i];
                j++;
            }
        }

        if (j == 3) {
            fwrite(rec, sizeof(record), 1, fileBinary);
            *flag = 1;
        }
    }
    return;
}