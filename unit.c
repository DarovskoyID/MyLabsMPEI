#include "unit.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int record_exists(FILE *bfile, int pos) {
    long size;
    fseek(bfile, 0, 2);
    size = ftell(bfile);
    long count = size / sizeof(record);
    return pos >= 1 && pos <= count;
}

void ChageRecordPosition(FILE *bfile, int pos1, int pos2) {
    record temp1, temp2;
    if(record_exists(bfile, pos1) && record_exists(bfile, pos2)){
        fseek(bfile, (pos1 - 1) * sizeof(record), 0);
        fread(&temp1, sizeof(record), 1, bfile);
        fseek(bfile, (pos2 - 1) * sizeof(record), 0);
        fread(&temp2, sizeof(record), 1, bfile);
        fseek(bfile, (pos2 - 1) * sizeof(record), 0);
        fwrite(&temp1, sizeof(record), 1, bfile);
        fseek(bfile, (pos1 - 1) * sizeof(record), 0);
        fwrite(&temp2, sizeof(record), 1, bfile);
    }
    else{
        printf("wrong position \n");
    }
    return;
}

int isGlasnei(char c) {
    int flag = 0;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
        flag = 1; // гласная
        }
    return flag; // не гласная
}


void DeleteGlasnie(FILE *bfile) {
    if (!bfile) return;
    record temp;
    long write_pos = 0;
    fseek(bfile, 0, SEEK_SET);
    while (fread(&temp, sizeof(record), 1, bfile) == 1) {
        if (!isGlasnei(temp[1])) {
            fseek(bfile, write_pos, SEEK_SET);
            fwrite(&temp, sizeof(record), 1, bfile);
            write_pos += sizeof(record);
            fseek(bfile, write_pos, SEEK_SET);
        }
    }
    int fd = fileno(bfile);
#ifdef _WIN32
    _chsize(fd, write_pos);
#else
    ftruncate(fd, write_pos);
#endif
}

void OutFile(FILE *bfile) {
    record temp;

    fseek(bfile, 0, 0);
    while (fread(&temp, sizeof(record), 1, bfile) == 1) {
        printf("%c %c %c\n", temp[0], temp[1], temp[2]);
    }
    return;
}
