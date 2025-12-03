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