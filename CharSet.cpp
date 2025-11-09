//
// Created by Иван on 23.10.2025.
//

#include "CharSet.h"
CharSet::CharSet(const char *elementsStr) : elements(nullptr), size(0) {
    int len = std::strlen(elementsStr);
    elements = new char[len + 1];

    for (int i = 0; i < len; i++) {
        char c = elementsStr[i];
        bool found = false;
        int j = 0;
        while ( j < size && !found) {
            if (elements[j] == c) {
                found = true;
            }
            j++;
        }

        if (!found) {
            elements[size++] = c;
        }
    }
}

CharSet::CharSet(const CharSet &setik, char n) : elements(nullptr), size(0) {
    int maxSize = setik.Size();
    if (maxSize > 0){

        elements = new char[maxSize + 1]();

        for (int i = 0; i < maxSize; i++) {
            char c = setik.Get(i);
            bool found = false;

            for (int j = 0; j < size; j++) {
                if (elements[j] == c) {
                    found = true;
                    break;
                }
            }

            if (!found && c <= n) {
                elements[size++] = c;
            }
        }
    }
}



CharSet::~CharSet()  {
    delete[] elements;
}

void CharSet::Sort() {
    char temp;
    for (int j = 1; j < size; j++) {
        for (int i = 0; i < size-j; i++) {
            if (elements[i] > elements[i+1]) {
                temp = elements[i];
                elements[i] = elements[i+1];
                elements[i+1] = temp;
            }
        }
    }
    return;
}

void CharSet::print() const{
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << '\n';
    return;
}

CharSet::operator char() const {
    char result = '\0';
    if (size > 0)
        result = elements[0];
    return result;
}

int CharSet::Size() const {
    return size;
}

char CharSet::Get(int i) const{
    char result = '\0';
    if(i < size) {
        result = elements[i];
    }
    return result;
}

void CharSet::Add(char c) {
    if(!inSet(c)) {
        char *temp = new char[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = elements[i];
        }
        temp[size] = c;
        delete[] elements;
        elements = temp;
        size += 1;
    }
    return;
}

void CharSet::Delete(char c) {
    if (inSet(c)) {
        bool flag = true;
        char *temp = new char[size-1];
        for (int i = 0; i < size; i ++) {
            if (elements[i] == c) flag = false;
            temp[ flag ? i : i-1] = elements[i];
        }
        delete[] elements;
        elements = temp;
        size -=1;
    }
}
bool CharSet::inSet(char c) {
    bool flag = false;
    int j = 0;
    while (j < size && !flag ){
        if (elements[j] == c) flag = true;
        else j++;
    }
    return flag;
}
