//
// Created by Иван on 03.12.2025.
//

#ifndef UNTITLED_LISTCHAR_H
#define UNTITLED_LISTCHAR_H

#include "List.h"
class CharList : public BaseList<char> {
public:
    bool checkChar(Node* head, Node*& tail);

    void clearSymbol(Node* head, Node*& tail);

    char GetAt(Node* head, Node*& tail, int index);

    int GetSize(Node* head, Node*& tail);

    Node* Concat(Node* head1, Node* head2, Node*& tail1, Node*& tail2);

    bool checkRange(Node* head, Node*& tail,char a, char b);
    void clearForRange(Node* head, Node*& tail,char a, char b);

};
#endif //UNTITLED_LISTCHAR_H
