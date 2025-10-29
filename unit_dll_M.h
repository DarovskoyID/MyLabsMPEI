//
// Created by Иван on 23.10.2025.
//

#ifndef UNIT_DLL_M_H
#define UNIT_DLL_M_H

#include <cstdio>
#include <cstddef>

#ifdef BUILDING_UNIT_DYLIB
    #define UNIT_API extern "C" __attribute__((visibility("default")))
#else
    #define UNIT_API extern "C"
#endif

UNIT_API void inputStringFromFile(char **inputString, int *len, FILE *file);
UNIT_API void splitter(const char *input, char ***output, int lenStr, int lenwords);
UNIT_API int countWords(const char *s, bool flag);
UNIT_API void sortWordsByLen(char **words, int n);


#endif //UNIT_DLL_M_H
