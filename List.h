#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class BaseList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
        Node() : data(T()), prev(nullptr), next(nullptr) {}
    };

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
        }
        else{
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = n;
            n->prev = cur;
        }

    }

    void DelFirst(Node*& head) {
        if (head) {
            Node *t = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete t;
        }
    }

    void DelLast(Node*& head) {
        if (head) {
            Node *cur = head;
            while (cur->next) cur = cur->next;
            if (cur->prev) {
                cur->prev->next = nullptr;
            } else {
                head = nullptr;
            }
            delete cur;
        }
    }

    T& GetFirst(Node* head) {
        if (!head) throw out_of_range("GetFirst");
        return head->data;
    }

    T& GetLast(Node* head) {
        if (!head) throw out_of_range("GetLast");
        Node* cur = head;
        while (cur->next) cur = cur->next;
        return cur->data;
    }

    void Print(Node* head) {
        cout << head << endl;
    }

    friend ostream& operator<<(ostream& os, Node* head) {
        os << "{";
        while (head) {
            os << head->data;
            if (head->next) os << ", ";
            head = head->next;
        }
        os << "}";
        return os;
    }

    virtual ~BaseList() {}
};


#endif