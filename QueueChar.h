//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_QUEUECHAR_H
#define UNTITLED_QUEUECHAR_H
#include "Queue.h"
class QueueChar : public QueueBase<char> {
public:

    int GetSize();

    bool checkChar();

    void clearSymbol();

    bool checkRange(char a, char b);
    void clearForRange(char a, char b);
};
#endif //UNTITLED_QUEUECHAR_H
