//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_LISTINT_H
#define UNTITLED_LISTINT_H
#include "List.h"
class IntList : public BaseList<int> {
public:
    int GetAt(Node* head, Node*& tail, int index);
    int GetSize(Node* head, Node*& tail);
    Node* Concat(Node* head1, Node* head2, Node*& tail1, Node*& tail2);
    bool checkDiv7(Node* head, Node* tail);
    void clearEven(Node* head, Node*& tail);
    bool checkRange(Node* head, Node*& tail,int a, int b);
    void clearForRange(Node* head, Node*& tail,int a, int b);

    };

#endif //UNTITLED_LISTINT_H
