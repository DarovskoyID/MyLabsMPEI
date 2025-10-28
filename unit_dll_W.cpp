#define UNIT_EXPORTS
#include "unit_dll_W.h"
#include <cstring>
#include <iostream>
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

UNIT_API void inputStringFromFile(char **inputString, size_t *len, FILE *file) {
    static char buf[1024];
    if (fgets(buf, sizeof(buf), file)) {
        *len = 0;
        while (buf[*len] && buf[*len] != '\n') (*len)++;
        *inputString = new char[*len + 1];
        for (size_t i = 0; i < *len; i++) (*inputString)[i] = buf[i];
        (*inputString)[*len] = '\0';
    } else {
        *inputString = nullptr;
    }
}
UNIT_API int countWords(const char *s) {
    if (*s == '\0') return 0;
    if (*s != ' ' && (s == 0 || *(s - 1) == ' '))
        return 1 + countWords(s + 1);
    return countWords(s + 1);
}
UNIT_API void copyWord(const char*src, char*dst, int start, int k, int len){
    if( k == len ){
        dst[k] = 0;
        return;
    }
    dst[k] = src[start+k]; copyWord(src, dst, start, k+1, len);
}
UNIT_API void splitWords(const char*str, char***out, int i, int len, int*wordIndex, int*start){
    if( i > len ) return;
    if( str[i] != ' ' && str[i] !=0 && *start == -1) *start = i;
    if( ( str[i] == ' ' || str[i]==0 ) && *start != -1 ){
        int wlen = i - *start;  (*out)[*wordIndex] = new char[wlen + 1];
        copyWord(str, (*out)[*wordIndex], *start, 0, wlen);  (*wordIndex)++;*start=-1;
    }
    splitWords(str,out,i+1,len,wordIndex,start);
}

UNIT_API void splitter(const char*str, char***out, int len, int count){
    *out = new char*[count];
    int start = -1, wordIndex = 0;
    splitWords(str, out, 0, len, &wordIndex, &start);
}

UNIT_API int CalculateLen(char *s){
    if( *s == '\0' ) return 0;
    return 1 + CalculateLen(s+1);
}

UNIT_API void sortStep(char **w, int i, int n){
    if( i >= n - 1 ) return;
    if( CalculateLen(w[i]) > CalculateLen(w[i+1]) ){
        char*t = w[i];  w[i] = w[i+1];  w[i+1] = t;}
    sortStep(w,i+1,n);
}

UNIT_API void sortWordsByLen(char **w,int n){
    if( n <= 1 ) return;
    sortStep(w,0,n);
    sortWordsByLen(w,n-1);
}