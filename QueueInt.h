//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_QUEUEINT_H
#define UNTITLED_QUEUEINT_H
#include "Queue.h"
class QueueInt : public QueueBase<int> {
public:
    int& GetAt(int index);

    int GetSize();

    QueueInt Concat(const QueueInt& q1, const QueueInt& q2);
};
#endif //UNTITLED_QUEUEINT_H
