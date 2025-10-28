#ifndef UNIT_DLL_W_H
#define UNIT_DLL_W_H

#include <windows.h>
#include <stdio.h>

#ifdef UNIT_EXPORTS
#define UNIT_API __declspec(dllexport)
#else
#define UNIT_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

UNIT_API void inputStringFromFile(char **inputString, size_t *len, FILE *file);
UNIT_API void splitter(const char *input, char ***output, int lenStr, int lenwords);
UNIT_API int countWords(const char *s);
UNIT_API int CalculateLen(char *inputString);
UNIT_API void sortWordsByLen(char **words, int n);

#ifdef __cplusplus
}
#endif

#endif // UNIT_DLL_W_H
