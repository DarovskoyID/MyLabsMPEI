#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <iostream>
#include <format>
#include <string>
using namespace std;

template <class T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    ~List() { clear(); }

    bool empty() const { return head == nullptr; }

    void push_back(const T& value) {
        Node* n = new Node(value);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    int size() {
        int i = 0;
        for (Node* p = head; p; p = p->next) i++;
        return i;
    }

    void push_front(const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    T pop_front() {
        if (!head) throw out_of_range("pop_front");
        Node* t = head;
        T temp = t->data;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete t;
        return temp;
    }

    T pop_back() {
        if (!tail) throw out_of_range("pop_back");
        Node* t = tail;
        T temp = t->data;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete t;
        return temp;
    }

    T& get_front() {
        if (!head) throw out_of_range("get_front");
        return head->data;
    }

    T& get_back() {
        if (!tail) throw out_of_range("get_back");
        return tail->data;
    }

    void clear() {
        while (!empty()) pop_front();
    }

    void print() const {
        for (Node* p = head; p; p = p->next)
            cout << p->data << " ";
        cout << "\n";
    }

    List& operator+=(const T& value){
        Node* n = new Node(value);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        return *this;
    }

    List& operator-=(int value){
        int i = 0;
        while (i < value) {
            if (!tail) break;
            Node* t = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete t;
            i++;
        }
        return *this;
    }

    friend List& operator+(List<T>& list1, List<T>& list2){
        if (!list1.tail) {
            list1.head = list1.tail = list2.head;
        } else if (list2.head) {
            list1.tail->next = list2.head;
            list2.head->prev = list1.tail;
            list1.tail = list2.tail;
        }
        return list1;
    }

    friend List& operator+(List<T>& list, const T& value){
        Node* n = new Node(value);
        if (!list.tail) {
            list.head = list.tail = n;
        } else {
            list.tail->next = n;
            n->prev = list.tail;
            list.tail = n;
        }
        return list;
    }

    T operator[](int m){
        int s = size();
        if (m >= s || m < 0)
            throw out_of_range(format("{} is bigger then {} or less then 0", m, s));
        int i = 0;
        Node* p = head;
        while (i != m){
            p = p->next;
            i++;
        }
        return p->data;
    }
};

#endif
