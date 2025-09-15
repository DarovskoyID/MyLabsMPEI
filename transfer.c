#include "transfer.h"
#include "record.h"

void transferFileToBFile(FILE *fileText, FILE *fileBinary) {
    struct record rec;
    char buffer[10];
    while (fgets(buffer, sizeof(buffer), fileText) != NULL) {
        sscanf(buffer, "%c %c %c", &rec.a, &rec.b, &rec.c);
        fwrite(&rec, sizeof(struct record), 1, fileBinary);
    }
}