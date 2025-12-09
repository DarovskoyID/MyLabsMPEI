#include "QueueChar.h"

bool QueueChar::checkChar() {
    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
        char c = X[l + i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            flag = true;
        }
    }
    return flag;
}

int QueueChar::GetSize() {
    return n;
}

void QueueChar::clearSymbol() {
    if (checkChar()){
        QueueChar temp;
        for (int i = 0; i < n; i++) {
            char c = X[l + i];
            if (c != '!' && c != ',' && c != '.' && c != '?' && c != ':' && c != ';' &&
                c != '-' && c != '\'' && c != '\"' && c != '(' && c != ')') {
                temp += c;
            }
        }

        *this = temp;
    }
    return;

}

void QueueChar::Sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int idx1 = l + j;
            int idx2 = l + j + 1;

            if (X[idx1] > X[idx2]) {
                char tmp = X[idx1];
                X[idx1] = X[idx2];
                X[idx2] = tmp;
            }
        }
    }
}