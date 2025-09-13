#include "unit.h"

void ChageRecordPosition(FILE *bfile, int pos1, int pos2) {
    struct record temp1, temp2;
    fseek(bfile, (pos1 - 1) * sizeof(struct record), 0);
    fread(&temp1, sizeof(struct record), 1, bfile);
    fseek(bfile, (pos2 - 1) * sizeof(struct record), 0);
    fread(&temp2, sizeof(struct record), 1, bfile);
    fseek(bfile, (pos2 - 1) * sizeof(struct record), 0);
    fwrite(&temp1, sizeof(struct record), 1, bfile);
    fseek(bfile, (pos1 - 1) * sizeof(struct record), 0);
    fwrite(&temp2, sizeof(struct record), 1, bfile);
}

void OutFile(FILE *bfile) {
    struct record temp;
    fseek(bfile, 0, 0);
    while (!feof(bfile)) {
        fread(&temp, sizeof(struct record), 1, bfile);
        printf("%c %c %c", temp.a, temp.b, temp.c);
    }
}
