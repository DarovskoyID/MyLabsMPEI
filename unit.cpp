#include "unit.h"
#include <iostream>
using namespace std;

void inputStringFromFile(char **inputString, size_t *len, FILE *file) {
    static char buf[1024];
    if (fgets(buf, sizeof(buf), file)) {
        *len = 0; while (buf[*len] && buf[*len] != '\n') (*len)++;
        *inputString = new char[*len + 1];
        for (size_t i = 0; i < *len; i++) (*inputString)[i] = buf[i];
        (*inputString)[*len] = '\0';
    } else *inputString = nullptr;
}

int countWords(const char *s) {
    int c = 0, in = 0;
    while (*s) { if (*s != ' ' && !in) { in = 1; c++; } else if (*s == ' ') in = 0; s++; }
    return c;
}

void splitter(const char *in, char ***out, int lenStr, int lenW) {
    *out = new char*[lenW]; int st = -1, j = 0;
    for (int i = 0; i <= lenStr; i++) {
        if (in[i] != ' ' && in[i] && st == -1) st = i;
        if ((in[i] == ' ' || in[i] == '\0') && st != -1) {
            int len = i - st; (*out)[j] = new char[len + 1];
            for (int k = 0; k < len; k++) (*out)[j][k] = in[st + k];
            (*out)[j++][len] = '\0'; st = -1;
        }
    }
}

int CalculateLen(char *s) { int i = 0; while (s[i]) i++; return i; }

void sortWordsByLen(char **w, int n) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; i++)
        if (CalculateLen(w[i]) > CalculateLen(w[i + 1])) {
            char *t = w[i];
            w[i] = w[i + 1];
            w[i + 1] = t;
        }
    sortWordsByLen(w, n - 1);
}
