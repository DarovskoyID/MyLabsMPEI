#include "ListInt.h"

int IntList::GetAt(Node* head, int index) {
    if (index < 0) throw out_of_range("Negative index");
    Node* current = head;
    for (int i = 0; i < index && current; i++) current = current->next;
    if (!current) throw out_of_range("Index out of range");
    return current->data;
}
int IntList::GetSize(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
IntList::Node* IntList::Concat(Node* head1, Node* head2) {
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

void IntList::Sort(Node* head) {
    if (!head || !head->next) return;

    bool swapped;

    do {
        swapped = false;
        Node* cur = head;

        while (cur->next) {
            if (cur->data > cur->next->data) {
                int tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = true;
            }
            cur = cur->next;
        }

    } while (swapped);
}