//
// Created by Иван on 23.10.2025.
//

#include "CharSet.h"
uint256 CharSet::_maskGeneration(const char *str) {
    uint256 resault;
    uint256 temp;
    for (int i = 0; i < std::strlen(str); i++) {
        temp.set(0);
        temp << (unsigned char)str[i];
        resault |= temp;
        temp.reset();
    }
    return resault;
}

char* CharSet::_clearDuplicate(const char *str, unsigned char n) {
    char c;
    bool found = false;
    int j = 0;
    int len = std::strlen(str);
    int size = 0;
    char* result = nullptr, *temp = nullptr;

    for (int i = 0; i < len; i++) {
        c = str[i];
        j = 0;
        found = false;
        while (j < size && !found ) {
            if (result[j] == c) {
                found = true;
            } else {
                j++;
            }
        }
        if (!found && (unsigned char)c <= n) {
            size +=1;
            temp = new char[size];
            for (int i = 0; i < size-1; i++) {
                temp[i] = result[i];
            }
            temp[size-1] = c;
            delete[] result;
            result = temp;
            delete[] temp;
        }
    }
    return result;
}


CharSet::CharSet(const char *elementsStr) {
    char* chars = _clearDuplicate(elementsStr);
    uint256 mask = _maskGeneration(chars);
    elements |= mask;
}

CharSet::CharSet(const CharSet &setik, unsigned char n) {
    char* temp = (char*)setik;
    temp = _clearDuplicate(temp, n);
    uint256 mask = _maskGeneration(temp);
    elements |= mask;

}

CharSet::~CharSet()  {
    elements.reset();
}

void CharSet::print() const{
    unsigned char c;
    for (int i = 0; i < 256; i++) {
        if (elements.test(i)) {
            c = (unsigned char)i;
            std::cout << c << " ";
        }
    }
    std::cout << '\n';
    return;
}

CharSet::operator char*() const {
    char *result, *temp;
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (elements.test(i)) {
            size++;
            temp = new char[size];
            for (int j = 0; j < size-1; j++) {
                temp[j] = result[j];
            }
            temp[size-1] = (char)i;
            delete[] result;
            result = temp;
            delete[] temp;
        }
    }
    return result;
}

int CharSet::Size() const {
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (elements.test(i)) size++;
    }
    return size;
}

bool CharSet::inSet(unsigned char c){
    return elements.test((int)c);
}

void CharSet::Add(char *c) {
    char *temp = _clearDuplicate(c);
    uint256 mask;
    mask = _maskGeneration(temp);
    elements |= mask;

    return;
}

void CharSet::Delete(char *c) {
    char *temp = _clearDuplicate(c);
    uint256 mask;
    mask = _maskGeneration(temp);
    elements &= ~mask;
    return;
}
