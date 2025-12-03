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