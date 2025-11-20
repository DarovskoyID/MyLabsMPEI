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

class CharSetException : public std::exception {
public:
    virtual const char* what() const noexcept = 0; // чисто виртуальная функция
};

class CharAlreadyExists : public CharSetException {
    const unsigned char ch;
public:
    CharAlreadyExists(const unsigned char c) : ch(c) {}
    const char* what() const noexcept override {
        return "Character already exists in the set";
    }
};

class CharNotFound : public CharSetException {
    const unsigned char ch;
public:
    CharNotFound(const unsigned char c) : ch(c) {}
    const char* what() const noexcept override {
        return "Character not found in the set";
    }
};

class IsNotCharFound : public CharSetException {
    const unsigned char ch;
public:
    IsNotCharFound(const unsigned char c) : ch(c) {}
    const char* what() const noexcept override {
        return "Character is not char";
    }
};

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
    CharSet(int a);
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
    CharSet& operator=(int p);
    CharSet operator+(CharSet &setik);
    CharSet operator-(CharSet &setik);
    CharSet operator*(CharSet &setik);
    bool operator>(CharSet &setik);
    bool operator<(CharSet &setik);
    bool operator>=(CharSet &setik);
    bool operator<=(CharSet &setik);
    CharSet& operator+=(CharSet &setik);
    CharSet& operator+=(const char* str);
    void print() const;
};

#endif //CHARSET_H
