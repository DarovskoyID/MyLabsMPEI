#include "ListChar.h"

bool CharList::checkChar(Node* head) {
    bool flag = false;
    for (Node* p = head; p && !flag; p = p->next) {
        char c = p->data;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            flag = true;
        }
    }
    return flag;
}

void CharList::clearSymbol(Node*& head) {
    if (checkChar(head)){
        Node* new_head = nullptr;

        for (Node* p = head; p; p = p->next) {
            char c = p->data;
            if (c != '!' && c != ',' && c != '.' && c != '?' && c != ':' && c != ';' &&
                c != '-' && c != '\'' && c != '\"' && c != '(' && c != ')') {
                AddLast(new_head, c);
            }
        }

        while (head) DelLast(head);

        for (Node* p = new_head; p; p = p->next) {
            AddLast(head, p->data);
        }

        while (new_head) DelLast(new_head);
    }
}

char CharList::GetAt(Node* head, int index) {
    if (index < 0) throw out_of_range("Negative index");
    Node* current = head;
    for (int i = 0; i < index && current; i++) current = current->next;
    if (!current) throw out_of_range("Index out of range");
    return current->data;
}

CharList::Node* CharList::Concat(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* current = head1;
    while (current) {
        AddLast(result, current->data);
        current = current->next;
    }
    current = head2;
    while (current) {
        AddLast(result, current->data);
        current = current->next;
    }
    return result;
}

int CharList::GetSize(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}