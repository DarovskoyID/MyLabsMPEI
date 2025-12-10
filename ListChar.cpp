#include "ListChar.h"

bool CharList::checkChar(Node* head, Node*& tail) {
    bool flag = false;
    for (Node* p = head; p && !flag; p = p->next) {
        char c = p->data;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            flag = true;
        }
    }
    return flag;
}

void CharList::clearSymbol(Node* head, Node*& tail) {
    if (checkChar(head, tail)){
        Node* new_head = nullptr;

        for (Node* p = head; p; p = p->next) {
            char c = p->data;
            if (c != '!' && c != ',' && c != '.' && c != '?' && c != ':' && c != ';' &&
                c != '-' && c != '\'' && c != '\"' && c != '(' && c != ')') {
                AddLast(new_head, tail, c);
            }
        }

        while (head) DelLast(head, tail);

        for (Node* p = new_head; p; p = p->next) {
            AddLast(head, tail, p->data);
        }

        while (new_head) DelLast(new_head, tail);
    }
}

char CharList::GetAt(Node* head, Node*& tail, int index) {
    if (index < 0) throw out_of_range("Negative index");
    Node* current = head;
    for (int i = 0; i < index && current; i++) current = current->next;
    if (!current) throw out_of_range("Index out of range");
    return current->data;
}

CharList::Node* CharList::Concat(Node* head1, Node* head2, Node*& tail1, Node*& tail2) {
    Node* result = nullptr;
    Node* current = head1;
    while (current) {
        AddLast(result, tail1, current->data);
        current = current->next;
    }
    current = head2;
    while (current) {
        AddLast(result, tail2, current->data);
        current = current->next;
    }
    return result;
}

int CharList::GetSize(Node* head, Node*& tail) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool CharList::checkRange(Node* head, Node*& tail,char a, char b){
    bool flag = false;
    for (Node* p = head; p && !flag; p = p->next) {
        char c = p->data;
        if ((c >= b || c <= a)) {
            flag = true;
        }
    }
    return flag;
}

void CharList::clearForRange(Node* head, Node*& tail,char a, char b){
    if (checkRange(head, tail, a, b)){
        Node* new_head = nullptr;

        for (Node* p = head; p; p = p->next) {
            char c = p->data;
            if ((c >= a && c <= b)) {
                AddLast(new_head, tail, c);
            }
        }

        while (head) DelLast(head, tail);

        for (Node* p = new_head; p; p = p->next) {
            AddLast(head, tail, p->data);
        }

        while (new_head) DelLast(new_head, tail);
    }
}