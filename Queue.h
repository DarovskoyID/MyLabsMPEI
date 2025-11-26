#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Queue {
private:
    T* X;
    int capacity;
    int n;
    int l;

    void grow() {
        int newCap = capacity * 2;
        T* newX = new T[newCap];
        for (int i = 0; i < n; i++)
            newX[i] = X[l + i];
        delete[] X;
        X = newX;
        capacity = newCap;
        l = 0;
    }

public:
    Queue(int cap = 10) : capacity(cap), n(0), l(0) {
        X = new T[capacity];
    }

    Queue(const Queue& other) : capacity(other.capacity), n(other.n), l(0) {
        X = new T[capacity];
        for (int i = 0; i < n; i++)
            X[i] = other.X[other.l + i];
    }

    ~Queue() { delete[] X; }

    bool operator!() const {
        return n == 0;
    }

    Queue& operator+=(const T& value) {
        if (l + n == capacity)
            grow();
        X[l + n] = value;
        n++;
        return *this;
    }

    Queue& operator--() {
        if (!*this) return *this;
        l++;
        n--;
        if (l > capacity / 2 && capacity > 10) {
            grow();
        }
        return *this;
    }

    T& operator*() {
        if (!*this) throw std::out_of_range("Queue is empty");
        return X[l];
    }

    T& operator[](int index) {
        if (index < 0 || index >= n)
            throw std::out_of_range("Index out of range");
        return X[l + index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= n)
            throw std::out_of_range("Index out of range");
        return X[l + index];
    }

    friend Queue operator+(const Queue& q1, const Queue& q2) {
        Queue result;
        for (int i = 0; i < q1.n; i++)
            result += q1[i];
        for (int i = 0; i < q2.n; i++)
            result += q2[i];
        return result;
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) return *this;
        delete[] X;
        capacity = other.capacity;
        n = other.n;
        l = 0;
        X = new T[capacity];
        for (int i = 0; i < n; i++)
            X[i] = other.X[other.l + i];
        return *this;
    }

    void Print() const {
        std::cout << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
        os << "{";
        for (int i = 0; i < q.n; i++) {
            os << q.X[q.l + i];
            if (i < q.n - 1) os << ", ";
        }
        os << "}";
        return os;
    }

};

#endif