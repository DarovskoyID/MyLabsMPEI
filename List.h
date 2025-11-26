#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class List {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
        Node() : data(T()), prev(nullptr), next(nullptr) {}
    };

    List() {}

    bool IsEmpty(Node* head) {
        return head == nullptr;
    }

    void AddFirst(Node*& head, const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void AddLast(Node*& head, const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* current = head;
        while (current->next) current = current->next;
        current->next = n;
        n->prev = current;
    }

    void AddMiddle(Node*& head, Node* after, const T& value) {
        if (!after) {
            AddFirst(head, value);
            return;
        }
        Node* n = new Node(value);
        n->prev = after;
        n->next = after->next;
        if (after->next) after->next->prev = n;
        after->next = n;
    }

    void DelFirst(Node*& head) {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete tmp;
    }

    void DelLast(Node*& head) {
        if (!head) return;
        Node* current = head;
        while (current->next) current = current->next;
        if (current->prev) {
            current->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete current;
    }

    void DelMiddle(Node*& head, Node* target) {
        if (!target) return;
        if (target == head) {
            DelFirst(head);
            return;
        }
        if (target->prev) target->prev->next = target->next;
        if (target->next) target->next->prev = target->prev;
        delete target;
    }

    T& GetFirst(Node* head) {
        if (!head) throw out_of_range("GetFirst: empty list");
        return head->data;
    }

    T& GetLast(Node* head) {
        if (!head) throw out_of_range("GetLast: empty list");
        Node* current = head;
        while (current->next) current = current->next;
        return current->data;
    }

    T& GetMiddle(Node* node) {
        if (!node) throw out_of_range("GetMiddle: null node");
        return node->data;
    }

    Node* MoveNext(Node* current) {
        return current ? current->next : nullptr;
    }

    Node* MovePrev(Node* current) {
        return current ? current->prev : nullptr;
    }

    void Print(Node* head) {
        cout << head << endl;
    }

    void Clear(Node*& head) {
        while (head) DelLast(head);
    }

    friend ostream& operator<<(ostream& os, Node* head) {
        os << "{";
        Node* current = head;
        while (current) {
            os << current->data;
            if (current->next) os << ", ";
            current = current->next;
        }
        os << "}";
        return os;
    }
};

#endif
