//
// Created by Иван on 23.10.2025.
//
//сделать симетрическую разность
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

    friend void Add(CharSet &setik, const char *c);
    friend void Delete(CharSet &setik, const char *c);
    friend void Add(CharSet &setik, CharSet &other);
    friend void Delete(CharSet &setik, CharSet &other);
    friend int Size(CharSet &setik);
    friend bool inSet(CharSet &setik, unsigned char c);

    friend CharSet operator+(CharSet &setik1, CharSet &setik2);
    friend CharSet operator-(CharSet &setik1, CharSet &setik2);
    friend CharSet operator*(CharSet &setik1, CharSet &setik2);
    friend CharSet operator/(CharSet &setik1, CharSet &setik2);
    friend bool operator>(CharSet &setik1, CharSet &setik2);
    friend bool operator<(CharSet &setik1, CharSet &setik2);
    friend bool operator>=(CharSet &setik1, CharSet &setik2);
    friend bool operator<=(CharSet &setik1, CharSet &setik2);
    friend std::ostream& operator<<(std::ostream& os, const CharSet& set);
    friend void print(CharSet &setik);

    void Add(const char *c);
    void Delete(const char *c);
    void Add(CharSet &setik);
    void Delete(CharSet &setik);
    int Size() const;
    bool inSet(unsigned char c) const;
    char* ToChar();
    CharSet& operator=(CharSet &&setik);
    CharSet& operator=(const char *str);
    CharSet& operator+=(CharSet &setik);
    CharSet& operator+=(const char* str);
    CharSet& operator-=(const char *c);
    void print() const;
};

#endif //CHARSET_H
