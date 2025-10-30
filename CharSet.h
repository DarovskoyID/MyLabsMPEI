//
// Created by Иван on 23.10.2025.
//

#ifndef CHARSET_H
#define CHARSET_H

#include<iostream>

typedef std::bitset<256> uint256;

class CharSet {
private:
    uint256 elements;
    uint256 _maskGeneration(const char* c);
    char *_clearDuplicate(const char *str, unsigned char n = 255);

public:
    CharSet(const char* elementsStr);
    CharSet(const CharSet &setik, unsigned char n);

    ~CharSet();

    void Add(char *c);
    void Delete(char *c);
    int Size() const;
    bool inSet(unsigned char c);
    void print() const;
    operator char*() const;
};




#endif //CHARSET_H
