//
// Created by Иван on 23.10.2025.
//
//перегрузить адд и делит чтоб работал с мно-вом
#ifndef CHARSET_H
#define CHARSET_H
#include <iostream>

class CharSet {
private:
    unsigned char data[64];
    unsigned char* mapping;
    int mappingSize;
    int mappingCapacity;

    void setBit(int index);
    void clrBit(int index);
    bool getBit(int index) const;
    int mapChar(unsigned char c) const;
    void addMapping(unsigned char c);

public:
    CharSet(const char* elementsStr);
    CharSet(CharSet &setik, unsigned char n);
    ~CharSet();

    void Add(const char *c);
    void Delete(const char *c);
    void Add(CharSet &setik);
    void Delete(CharSet &setik);
    int Size() const;
    bool inSet(unsigned char c) const;
    char* ToChar();
    void print() const;
};

#endif //CHARSET_H
