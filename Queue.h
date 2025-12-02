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
    int d;

    void grow_right(int add = 10) {
        int newCap = capacity + add;
        T* newX = new T[newCap];

        for (int i = 0; i < n; i++)
            newX[l + i] = X[l + i];

        delete[] X;
        X = newX;

        d += add;
        capacity = newCap;
    }

    void grow_left(int add = 10) {
        int newCap = capacity + add;
        T* newX = new T[newCap];

        int newL = l + add;

        for (int i = 0; i < n; i++)
            newX[newL + i] = X[l + i];

        delete[] X;
        X = newX;

        l = newL;
        capacity = newCap;
    }

public:
    Queue(int L = 5, int D = 5) {
        l = L;
        d = D;
        capacity = l + d;
        n = 0;
        X = new T[capacity];
    }

    Queue(const T& value) {
        capacity = 3;
        l = 1;
        d = 1;
        n = 1;
        X = new T[capacity];
        X[l] = value;
    }

    Queue(const Queue& other) {
        capacity = other.capacity;
        n = other.n;
        l = other.l;
        d = other.d;

        X = new T[capacity];
        for (int i = 0; i < capacity; i++)
            X[i] = other.X[i];
    }

    ~Queue() { delete[] X; }

    bool operator!() const { return n == 0; }
    int size() const { return n; }

    Queue& operator+=(const T& value) {
        if (d == 0)
            grow_right();

        X[l + n] = value;
        n++;
        d--;

        return *this;
    }

    Queue& operator--() {
        if (!*this) return *this;
        l++;
        n--;
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

    void TopToBottom() {
        if (n <= 1) return;

        T temp = X[l];

        for (int i = 0; i < n - 1; i++)
            X[l + i] = X[l + i + 1];

        X[l + n - 1] = temp;


    }

    friend Queue operator+(const Queue& q1, const Queue& q2) {
        Queue result(q1);

        while (result.d < q2.n)
            result.grow_right();

        for (int i = 0; i < q2.n; i++)
            result.X[result.l + result.n + i] = q2.X[q2.l + i];

        result.n += q2.n;
        result.d -= q2.n;

        return result;
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) return *this;

        delete[] X;

        capacity = other.capacity;
        n = other.n;
        l = other.l;
        d = other.d;

        X = new T[capacity];

        for (int i = 0; i < capacity; i++)
            X[i] = other.X[i];

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
