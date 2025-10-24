//
// Created by Иван on 23.10.2025.
//

#ifndef CHARSET_H
#define CHARSET_H

#include<iostream>

class CharSet {
private:
    char* elements;
    int size;
public:
    CharSet(const char* elementsStr);
    CharSet(const CharSet &setik, char n);

    ~CharSet();

    int Size() const;
    char Get(int i) const;
    void print() const;
};




#endif //CHARSET_H
