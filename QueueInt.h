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

    bool checkDiv7();
    void clearEven();

    bool checkRange(int a, int b);
    void clearForRange(int a, int b);

};
#endif //UNTITLED_QUEUEINT_H
