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


void QueueInt::Sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int idx1 = l + j;
            int idx2 = l + j + 1;

            if (X[idx1] > X[idx2]) {
                int tmp = X[idx1];
                X[idx1] = X[idx2];
                X[idx2] = tmp;
            }
        }
    }
}

void QueueInt::Sort() {
    QueueInt q(*this);
    n = 0;
    d = 0;
    

    while (!(!q)) {
        int minVal = *q;
        int n0 = q.size();

        for (int i = 0; i < n0; i++) {
            int v = *q;
            if (v < minVal) minVal = v;
            q.TopToBottom();
        }

        bool removed = false;
        for (int i = 0; i < n0; i++) {
            int v = *q;
            --q;
            if (!removed && v == minVal) {
                removed = true;
            } else {
                q += v;
            }
        }

        *this += minVal;
    }
}