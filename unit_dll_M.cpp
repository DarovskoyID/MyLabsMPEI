#include "unit_dll_M.h"
#include <iostream>


__attribute__((constructor))
static void library_init() {
    printf("[unit_dylib] Library loaded.\n");
}

__attribute__((destructor))
static void library_fini() {
    printf("[unit_dylib] Library unloaded.\n");
}

extern "C" void inputStringFromFile(char **inputString, int *len, FILE *file) {
    *inputString = nullptr;
    *len = 0;
    int c;
    while ((c = fgetc(file)) != EOF && c != '\0') {
        char *newStr = new char[*len + 2];
        for (int i = 0; i < *len; i++)
            newStr[i] = (*inputString)[i];
        newStr[*len] = (char)c;
        newStr[*len + 1] = '\0';
        delete[] *inputString;
        *inputString = newStr;
        (*len)++;
    }
}


UNIT_API int countWords(const char *s, bool flag) {
    if (*s == '\0') return 0;
    if (*s != ' ' && (*(s - 1) == ' ' || flag))
        return 1 + countWords(s + 1, false);
    return countWords(s + 1, false);
}

void copyWord(const char*src, char*dst, int start, int k, int len){
    if( k == len ){
        dst[k] = 0;
        return;
    }
    dst[k] = src[start+k]; copyWord(src, dst, start, k+1, len);
}

void splitWords(const char*str, char***out, int i, int len, int*wordIndex, int*start){
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

int CalculateLen(char *s){
    if( *s == '\0' ) return 0;
    return 1 + CalculateLen(s+1);
}

void sortStep(char **w, int i, int n){
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