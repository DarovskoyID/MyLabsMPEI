#include "transfer.h"
#include "record.h"

void transferFileToBFile(FILE *fileText, FILE *fileBinary) {
    struct record rec;
    while (!feof(fileText)) {
        fscanf(fileText, "%c %c %c", &rec.a, &rec.b, &rec.c);
        fwrite(&rec, sizeof(struct record), 1, fileBinary);
    }
}