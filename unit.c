#include "unit.h"

int record_exists(FILE *bfile, int pos) {
    long size;
    fseek(bfile, 0, 2);
    size = ftell(bfile);
    long count = size / sizeof(struct record);
    return pos >= 1 && pos <= count;
}

void ChageRecordPosition(FILE *bfile, int pos1, int pos2) {
    struct record temp1, temp2;
    if(record_exists(bfile, pos1) && record_exists(bfile, pos2)){
        fseek(bfile, (pos1 - 1) * sizeof(struct record), 0);
        fread(&temp1, sizeof(struct record), 1, bfile);
        fseek(bfile, (pos2 - 1) * sizeof(struct record), 0);
        fread(&temp2, sizeof(struct record), 1, bfile);
        fseek(bfile, (pos2 - 1) * sizeof(struct record), 0);
        fwrite(&temp1, sizeof(struct record), 1, bfile);
        fseek(bfile, (pos1 - 1) * sizeof(struct record), 0);
        fwrite(&temp2, sizeof(struct record), 1, bfile);
    }
    else{
        printf("wrong position \n");
    }


}

void OutFile(FILE *bfile) {
    struct record temp;

    fseek(bfile, 0, 0);
    while (fread(&temp, sizeof(struct record), 1, bfile) == 1) {
        printf("%c %c %c\n", temp.a, temp.b, temp.c);
    }
}
