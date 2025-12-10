#include "ListInt.h"

int IntList::GetAt(Node* head, Node*& tail, int index) {
    if (index < 0) throw out_of_range("Negative index");
    Node* current = head;
    for (int i = 0; i < index && current; i++) current = current->next;
    if (!current) throw out_of_range("Index out of range");
    return current->data;
}
int IntList::GetSize(Node* head, Node*& tail) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
IntList::Node* IntList::Concat(Node* head1, Node* head2, Node*& tail1, Node*& tail2) {
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

bool IntList::checkDiv7(Node* head, Node* tail) {
    int total = 0;
    int cnt7 = 0;

    for (Node* p = head; p; p = p->next) {
        total++;
        if (p->data % 7 == 0) cnt7++;
    }

    return (total > 0 && cnt7 > total / 2);
}

void IntList::clearEven(Node* head, Node*& tail) {
    if (checkDiv7(head, tail)) {
        Node* new_head = nullptr;

        for (Node* p = head; p; p = p->next) {
            if (p->data % 2 != 0) {
                AddLast(new_head, tail, p->data);
            }
        }

        while (head) {
            DelLast(head, tail);
        }

        for (Node* p = new_head; p; p = p->next) {
            AddLast(head, tail, p->data);
        }

        while (new_head) {
            DelLast(new_head, tail);
        }
    }
}

bool IntList::checkRange(Node* head, Node*& tail,int a, int b){
    bool flag = false;
    for (Node* p = head; p && !flag; p = p->next) {
        char c = p->data;
        if ((c >= b || c <= a)) {
            flag = true;
        }
    }
    return flag;
}

void IntList::clearForRange(Node* head, Node*& tail,int a, int b){
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

