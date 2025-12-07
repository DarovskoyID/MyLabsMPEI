#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class QueueBase {
protected:
    T* X;
    int n;
    int l;
    int d;

    void grow_right(int add = 10) {
        int newCap = l + d + add;
        T* newX = new T[newCap];
        for (int i = 0; i < n; i++)
            newX[l + i] = X[l + i];
        delete[] X;
        X = newX;
        d += add;
    }

    void grow_left(int add = 10) {
        int newCap = l + d + add;
        T* newX = new T[newCap];
        int newL = l + add;
        for (int i = 0; i < n; i++)
            newX[newL + i] = X[l + i];
        delete[] X;
        X = newX;
        l = newL;
    }

public:
    QueueBase(int L = 5, int D = 5) : n(0), l(L), d(D) { X = new T[l + d]; }
    QueueBase(const T& value) : n(1), l(1), d(1) { X = new T[l + d]; X[l] = value; }
    QueueBase(const QueueBase& other) {
        n = other.n;
        l = 0;
        d = other.n;
        X = new T[n];
        for (int i = 0; i < n; i++)
            X[i] = other.X[other.l + i];
    }

     ~QueueBase() { delete[] X; }

    bool operator!() const { return n == 0; }
    int size() const { return n; }

     QueueBase& operator+=(const T& value) {
        if (d == 0) grow_right();
        X[l + n] = value;
        n++;
        d--;
        return *this;
    }

     QueueBase& operator--() {
        if (!(!*this)){
            X[l] = T();

            l++;
            n--;
        }

        return *this;
    }

     T& operator*() {
        if (!*this) throw std::out_of_range("Queue is empty");
        return X[l];
    }

     T& operator[](int index) {
        if (index < 0 || index >= n) throw std::out_of_range("Index out of range");
        return X[l + index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= n) throw std::out_of_range("Index out of range");
        return X[l + index];
    }

    void TopToBottom() {
        if (n > 1){
            T temp = X[l];
            for (int i = 0; i < n - 1; i++) X[l + i] = X[l + i + 1];
            X[l + n - 1] = temp;
        }

    }

     void Print() const {
        std::cout << "{";
        for (int i = 0; i < n; i++) {
            std::cout << X[l + i];
            if (i < n - 1) std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }

     QueueBase& operator=(QueueBase& other) {
         if (this != &other) {
             delete[] X;
             n = other.n;
             l = 0;
             d = other.n;
             X = new char[n];
             for (int i = 0; i < n; i++)
                 X[i] = other.X[other.l + i];
         }
         return *this;
    }

    QueueBase operator+(const QueueBase& other) {
        QueueBase result(*this);
        for (int i = 0; i < other.n; i++)
            result += other.X[other.l + i];
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const QueueBase& q) {
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