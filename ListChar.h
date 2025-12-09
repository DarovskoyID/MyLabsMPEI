//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_LISTCHAR_H
#define UNTITLED_LISTCHAR_H

#include "List.h"
class CharList : public BaseList<char> {
public:
    bool checkChar(Node* head);

    void clearSymbol(Node*& head);

    char GetAt(Node* head, int index);

    int GetSize(Node* head);

    Node* Concat(Node* head1, Node* head2);

    void Sort(Node* head);
};
#endif //UNTITLED_LISTCHAR_H
