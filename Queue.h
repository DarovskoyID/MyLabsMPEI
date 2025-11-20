//
// Created by Иван on 20.11.2025.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

#include <iostream>

template <class T>
class Queue {
private:
    T* arr;
    int capacity;
    int head;
    int tail;
    int count;

    void grow() {
        int newCap = capacity * 2;
        T* newArr = new T[newCap];

        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(head + i) % capacity];
        }

        delete[] arr;
        arr = newArr;

        head = 0;
        tail = count;
        capacity = newCap;
        return;
    }

public:
    Queue(int cap = 10)
            : capacity(cap), head(0), tail(0), count(0)
    {
        arr = new T[capacity];
    }

    ~Queue() { delete[] arr; }

    bool empty() const { return count == 0; }

    void push(const T& value) {
        if (count == capacity)
            grow();

        arr[tail] = value;
        tail = (tail + 1) % capacity;
        ++count;
        return;
    }

    void pop() {
        if (empty()) return;
        for (int i = 1; i < count; i++)
            arr[i - 1] = arr[(head + i) % capacity];
        head = 0;
        tail = count - 1;
        count--;
    }


    T& front() {
        return arr[head];
    }

    void print() const {
        int idx = head;
        for (int i = 0; i < count; i++) {
            std::cout << arr[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        std::cout << "\n";
        return;
    }

    friend Queue& operator+(Queue q1, Queue q2){
        int newSize = q1.count + q2.count;
        if (newSize > q1.capacity) {
            int newCap = q1.capacity;
            while (newCap < newSize) newCap *= 2;
            T* newArr = new T[newCap];
            for (int i = 0; i < q1.count; i++)
                newArr[i] = q1.arr[(q1.head + i) % q1.capacity];
            delete[] q1.arr;
            q1.arr = newArr;
            q1.capacity = newCap;
            q1.head = 0;
            q1.tail = q1.count;
        }
        for (int i = 0; i < q2.count; i++)
            q1.arr[(q1.tail + i) % q1.capacity] = q2.arr[(q2.head + i) % q2.capacity];
        q1.tail = (q1.tail + q2.count) % q1.capacity;
        q1.count += q2.count;
        return q1;
    }

    friend Queue& operator+(Queue q1, T value){
        if (q1.count == q1.capacity) {
            int newCap = q1.capacity * 2;
            T* newArr = new T[newCap];
            for (int i = 0; i < q1.count; i++)
                newArr[i] = q1.arr[(q1.head + i) % q1.capacity];
            delete[] q1.arr;
            q1.arr = newArr;
            q1.capacity = newCap;
            q1.head = 0;
            q1.tail = q1.count;
        }
        q1.arr[q1.tail] = value;
        q1.tail = (q1.tail + 1) % q1.capacity;
        q1.count++;
        return q1;
    }

    Queue& operator+=(const T& value){
        if (count == capacity) {
            int newCap = capacity * 2;
            T* newArr = new T[newCap];
            for (int i = 0; i < count; i++)
                newArr[i] = arr[(head + i) % capacity];
            delete[] arr;
            arr = newArr;
            capacity = newCap;
            head = 0;
            tail = count;
        }
        arr[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
        return *this;
    }

    Queue& operator-=(int m){
        if (m >= count) {
            head = tail = count = 0;
        } else {
            for (int i = 0; i < count - m; i++)
                arr[i] = arr[(head + m + i) % capacity];
            head = 0;
            tail = count - m;
            count -= m;
        }
        return *this;
    }


    Queue& operator[](int m){
        return arr[(head + m) % capacity];
    }

};

#endif //UNTITLED_QUEUE_H
