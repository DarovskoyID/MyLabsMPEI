#ifndef UNIT_H
#define UNIT_H
#include <stdio.h>

#include "record.h"
#include <fcntl.h>

void DeleteGlasnie(FILE *bfile);

void ChageRecordPosition(FILE *bfile, int pos1, int pos2);
void OutFile(FILE *bfile);
#endif //UNIT_H
