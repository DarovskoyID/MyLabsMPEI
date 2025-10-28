#include "unit.h"
//UNIX
//void inputStringFromFile(char **inputString, int *len, FILE *file) {
//    getline(inputString, len, file);
//    return;
//}
void inputStringFromFile(char **s, int *len, FILE *f) {
    int c, i = 0, cap = 128;
    *s = malloc(cap);
    while( ( c = fgetc(f) ) != EOF && c != '\n' ){
        if( i+1 >= cap ){ cap *= 2; *s = realloc(*s,cap);}
        (*s)[i++] = c;}
    (*s)[i] = 0; *len = i;}
int countWords(const char *s) {
    if (*s == '\0') return 0;
    if (*s != ' ' && (s == 0 || *(s - 1) == ' ')) return 1 + countWords(s + 1);
    return countWords(s + 1);
}
void copyWord(const char*src, char*dst, int start, int k, int len){
    if( k == len ){ dst[k] = 0; return; } dst[k] = src[start+k]; copyWord(src, dst, start, k+1, len); }
void splitWords(const char*str, char***out, int i, int len, int*wordIndex, int*start){
    if( i > len )return;
    if( str[i] != ' ' && str[i] !=0 && *start == -1) *start = i;
    if( ( str[i] == ' ' || str[i]==0 ) && *start != -1 ){
        int wlen = i - *start;  (*out)[*wordIndex]=malloc(wlen+1);
        copyWord(str, (*out)[*wordIndex], *start, 0, wlen);  (*wordIndex)++;*start=-1;}
    splitWords(str,out,i+1,len,wordIndex,start);}
void splitter(const char*str, char***out, int len, int count){
    *out = malloc(count*sizeof(char*));
    int start = -1, wordIndex = 0;
    splitWords(str, out, 0, len, &wordIndex, &start);}
int CalculateLen(char *s){
    if( *s == '\0' ) return 0;
    return 1 + CalculateLen(s+1);}
void sortStep(char **w, int i, int n){
    if( i >= n - 1 ) return;
    if( CalculateLen(w[i]) > CalculateLen(w[i+1]) ){
        char*t = w[i];  w[i] = w[i+1];  w[i+1] = t;}
    sortStep(w,i+1,n);}
void sortWordsByLen(char **w,int n){
    if( n <= 1 ) return;
    sortStep(w,0,n);
    sortWordsByLen(w,n-1);}