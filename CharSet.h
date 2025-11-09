//
// Created by Иван on 23.10.2025.
//
//перегрузить адд и делит чтоб работал с мно-вом
#ifndef CHARSET_H
#define CHARSET_H


//Операция присваивания; операция присваивания перемещением;
//операции сравнения; операция «+» – объединение множеств;
//операция «*» – пересечение множеств; операция «-» –
//вычитание множеств; операция «+=» – добавление нового элемента в множество.


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
    CharSet(const CharSet& other);
    CharSet(CharSet &setik, unsigned char n);
    ~CharSet();

    void Add(const char *c);
    void Delete(const char *c);
    void Add(CharSet &setik);
    void Delete(CharSet &setik);
    int Size() const;
    bool inSet(unsigned char c) const;
    char* ToChar();
    CharSet& operator=(CharSet &&setik);
    CharSet& operator=(const char* str);
    friend CharSet operator+(CharSet &setik1, CharSet &setik2);
    friend CharSet operator-(CharSet &setik1, CharSet &setik2);
    friend CharSet operator*(CharSet &setik1, CharSet &setik2);
    bool operator>(CharSet &setik);
    bool operator<(CharSet &setik);
    bool operator>=(CharSet &setik);
    bool operator<=(CharSet &setik);
    CharSet& operator+=(CharSet &setik);
    CharSet& operator+=(const char* str);
    void print() const;
};

#endif //CHARSET_H
