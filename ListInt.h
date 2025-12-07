//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_LISTINT_H
#define UNTITLED_LISTINT_H
#include "List.h"
class IntList : public BaseList<int> {
public:
    int GetAt(Node* head, int index);
    int GetSize(Node* head);
    Node* Concat(Node* head1, Node* head2);
};

#endif //UNTITLED_LISTINT_H
