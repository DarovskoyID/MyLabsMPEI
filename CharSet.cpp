//
// Created by Иван on 23.10.2025.
//

#include "CharSet.h"
CharSet::CharSet(const char *elementsStr) : elements(nullptr), size(0) {
    int len = 0;
    while (elementsStr[len] != '\0') {
        len++;
    }
    elements = new char[size];
    for (int i = 0; i < len; i++) {
        char c = elementsStr[i];
        int found = 0, j = 0;
        while (j < size && !found){
            if (elements[j] == c) {
                found = 1;
            } else {
                j++;
            }
        }
        if (!found) {
            elements[size] = c;
            size++;
        }
    }
}

CharSet::CharSet(const CharSet &setik, char n) : elements(nullptr), size(0) {
    int maxSize = setik.Size();
    if (maxSize > 0) {
        elements = new char[maxSize]; // максимум возможных элементов

        for (int i = 0; i < maxSize; i++) {
            char c = setik.Get(i);
            int found = 0;
            int j = 0;

            while (j < size && !found) {
                if (elements[j] == c) {
                    found = 1;
                } else {
                    j++;
                }
            }

            if (!found && c <= n) {
                elements[size] = c;
                size++;
            }
        }

        // уменьшаем массив только если реально что-то добавлено
        if (size < maxSize) {
            char* temp = new char[size];
            for (int i = 0; i < size; i++) temp[i] = elements[i];
            delete[] elements;
            elements = temp;
        }

    }
}


CharSet::~CharSet()  {
    delete[] elements;
}

int CharSet::Size() const {
    return size;
}

char CharSet::Get(int i) const{
    char result;
    if(i < size) {
        result = elements[i];
    }
    return result;
}



void CharSet::print() const{
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << '\n';
}

