#include "QueueInt.h"

int& QueueInt::GetAt(int index) {
    if (index < 0) throw std::out_of_range("Negative index");
    if (index >= n) throw std::out_of_range("Index out of range");
    return X[l + index];
}

int QueueInt::GetSize() {
    return n;
}

QueueInt QueueInt::Concat(const QueueInt& q1, const QueueInt& q2) {
    QueueInt result(q1);

    for (int i = 0; i < q2.n; i++) {
        result += q2.X[q2.l + i];
    }

    return result;
}

bool QueueInt::checkDiv7() {
    int cnt7 = 0;

    for (int i = 0; i < n; i++) {
        int v = X[l + i];
        if (v % 7 == 0) cnt7++;
    }

    return (n > 0 && cnt7 > n / 2);
}

void QueueInt::clearEven() {
    if (checkDiv7()) {
        QueueInt temp;

        for (int i = 0; i < n; i++) {
            int v = X[l + i];
            if (v % 2 != 0) {
                temp += v;
            }
        }

        *this = temp;
    }
}

bool QueueInt::checkRange(int a, int b){
    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
        char c = X[l + i];
        if ((c >= b || c <= a)) {
            flag = true;
        }
    }
    return flag;
}
void QueueInt::clearForRange(int a, int b){
    if (checkRange(a, b)){
        QueueInt temp;
        for (int i = 0; i < n; i++) {
            char c = X[l + i];
            if ((c >= a && c <= b)) {
                temp += c;
            }
        }

        *this = temp;
    }
    return;
}