#include "CharSet.h"

void CharSet::setBit(int index){
    int idx = index >> 2;
    int bit = index & 3;
    data[idx] |= (1 << bit);
    return;
}

void CharSet::clrBit(int index){
    int idx = index >> 2;
    int bit = index & 3;
    data[idx] &= ~(1 << bit);
    return;
}

bool CharSet::getBit(int index) const{
    int idx = index >> 2;
    int bit = index & 3;
    return (data[idx] >> bit) & 1;
}

int CharSet::mapChar(unsigned char c) const{
    int i = 0;
    while(i < mappingSize){
        if(mapping[i] == c) return i;
        i = i + 1;
    }
    return -1;
}

void CharSet::addMapping(unsigned char c){
    if(mappingSize >= mappingCapacity){
        int newCap = mappingCapacity + 4;
        unsigned char* newMap = new unsigned char[newCap];
        int i = 0;
        while(i < mappingSize){
            newMap[i] = mapping[i];
            i = i + 1;
        }
        delete[] mapping;
        mapping = newMap;
        mappingCapacity = newCap;
    }
    mapping[mappingSize] = c;
    mappingSize = mappingSize + 1;
    return;
}

CharSet::CharSet(const char* elementsStr){
    int i = 0;
    while(i < 64){
        data[i] = 0;
        i = i + 1;
    }
    mappingCapacity = 4;
    mappingSize = 0;
    mapping = new unsigned char[mappingCapacity];

    i = 0;
    while(elementsStr[i] != 0){
        if(mapChar(elementsStr[i]) < 0){
            addMapping(elementsStr[i]);
        }
        int idx = mapChar(elementsStr[i]);
        if(idx >= 0){
            setBit(idx);
        }
        i = i + 1;
    }
}

CharSet::CharSet(const CharSet& other)
{
    for (int i = 0; i < 64; ++i)
        data[i] = other.data[i];

    mappingCapacity = other.mappingCapacity;
    mappingSize     = other.mappingSize;

    mapping = new unsigned char[mappingCapacity];
    for (int i = 0; i < mappingSize; ++i)
        mapping[i] = other.mapping[i];
}

void CharSet::Add(const char *c){
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx < 0){
            addMapping((unsigned char)c[i]);
            idx = mappingSize - 1;
        }
        setBit(idx);
        i = i + 1;
    }
    return;
}
void CharSet::Add(CharSet &setik) {
    char* c = setik.ToChar();
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx < 0){
            addMapping((unsigned char)c[i]);
            idx = mappingSize - 1;
        }
        setBit(idx);
        i = i + 1;
    }
    return;
}

void CharSet::Delete(CharSet &setik) {
    char *c = setik.ToChar();
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx >= 0){
            clrBit(idx);
        }
        i = i + 1;
    }
    return;
}
void CharSet::Delete(const char *c){
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx >= 0){
            clrBit(idx);
        }
        i = i + 1;
    }
    return;
}

int CharSet::Size() const{
    int cnt = 0;
    int i = 0;
    while(i < mappingSize){
        if(getBit(i)){
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return cnt;
}

bool CharSet::inSet(unsigned char c) const{
    int idx = mapChar(c);
    if(idx < 0) return false;
    return getBit(idx);
}

CharSet::CharSet(CharSet &setik, unsigned char n){
    int i = 0;
    while(i < 64){
        data[i] = 0;
        i = i + 1;
    }
    mappingCapacity = 4;
    mappingSize = 0;
    mapping = new unsigned char[mappingCapacity];

    char* t = setik.ToChar();
    i = 0;
    while(t[i] != 0){
        int idx = mapChar((unsigned char)t[i]);
        if(idx < 0){
            addMapping((unsigned char)t[i]);
            idx = mappingSize - 1;
        }
        if(idx <= n){
            setBit(idx);
        }
        i = i + 1;
    }
    delete[] t;
}

CharSet::~CharSet(){
    int i = 0;
    while(i < 64){
        data[i] = 0;
        i = i + 1;
    }
    delete[] mapping;
}

void Add(CharSet &setik, const char *c){
    int i = 0;
    while(c[i] != 0){
        int idx = setik.mapChar((unsigned char)c[i]);
        if(idx < 0){
            setik.addMapping((unsigned char)c[i]);
            idx = setik.mappingSize - 1;
        }
        setik.setBit(idx);
        i = i + 1;
    }
    return;
}
void Add(CharSet &setik, CharSet &other) {
    char* c = other.ToChar();
    int i = 0;
    while(c[i] != 0){
        int idx = setik.mapChar((unsigned char)c[i]);
        if(idx < 0){
            setik.addMapping((unsigned char)c[i]);
            idx = setik.mappingSize - 1;
        }
        setik.setBit(idx);
        i = i + 1;
    }
    return;
}

void Delete(CharSet &setik, CharSet &other) {
    char *c = other.ToChar();
    int i = 0;
    while(c[i] != 0){
        int idx = setik.mapChar((unsigned char)c[i]);
        if(idx >= 0){
            setik.clrBit(idx);
        }
        i = i + 1;
    }
    return;
}
void Delete(CharSet &setik, const char *c){
    int i = 0;
    while(c[i] != 0){
        int idx = setik.mapChar((unsigned char)c[i]);
        if(idx >= 0){
            setik.clrBit(idx);
        }
        i = i + 1;
    }
    return;
}

int Size(CharSet &setik) {
    int cnt = 0;
    int i = 0;
    while(i < setik.mappingSize){
        if(setik.getBit(i)){
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return cnt;
}

bool inSet(CharSet &setik, unsigned char c) {
    int idx = setik.mapChar(c);
    if(idx < 0) return false;
    return setik.getBit(idx);
}

char* CharSet::ToChar(){
    int s = Size();
    char* r = new char[s+1];
    int j = 0;
    int i = 0;
    while(i < mappingSize){
        if(getBit(i)){
            r[j] = mapping[i];
            j = j + 1;
        }
        i = i + 1;
    }
    r[j] = 0;
    return r;
}

CharSet& CharSet::operator=(CharSet&& other) {
    if (this != &other){
        delete[] mapping;

        for (int i = 0; i < 64; ++i)
            data[i] = other.data[i];

        mapping = other.mapping;
        mappingCapacity = other.mappingCapacity;
        mappingSize = other.mappingSize;

        for (int i = 0; i < 64; ++i)
            other.data[i] = 0;
        other.mapping = nullptr;
        other.mappingCapacity = 0;
        other.mappingSize = 0;
    }
    return *this;
}

CharSet& CharSet::operator=(const char *str) {
    int i = 0;
    while(i < 64){
        data[i] = 0;
        i = i + 1;
    }

    delete[] mapping;

    mappingCapacity = 4;
    mappingSize = 0;
    mapping = new unsigned char[mappingCapacity];

    i = 0;
    while(str[i] != 0){
        if(mapChar(str[i]) < 0){
            addMapping(str[i]);
        }
        int idx = mapChar(str[i]);
        if(idx >= 0){
            setBit(idx);
        }
        i = i + 1;
    }
    return *this;
}


CharSet operator+(CharSet &setik1, CharSet &setik2) {
    char* c = setik1.ToChar();
    CharSet t("");
    int i = 0;
    while(c[i] != 0){
        int idx = t.mapChar((unsigned char)c[i]);
        if(idx < 0){
            t.addMapping((unsigned char)c[i]);
            idx = t.mappingSize - 1;
        }
        if(inSet(setik1, c[i]) || inSet(setik2, c[i]))
            t.setBit(idx);
        i = i + 1;
    }
    return t;
}


CharSet operator-(CharSet &setik1, CharSet &setik2) {
    CharSet result("");
    char* c = setik1.ToChar();
    for (int i = 0; c[i] != 0; ++i) {
        unsigned char ch = (unsigned char)c[i];
        if (inSet(setik1, ch) && !inSet(setik2, ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }
    return result;
}

CharSet operator*(CharSet &setik1, CharSet &setik2) {
    CharSet result("");
    char* c = setik1.ToChar();
    for (int i = 0; c[i] != 0; ++i) {
        unsigned char ch = (unsigned char)c[i];
        if (inSet(setik1, ch) && inSet(setik2, ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }
    return result;
}


bool operator>(CharSet &setik1, CharSet &setik2) {
    return Size(setik1) > Size(setik2);
}

bool operator<(CharSet &setik1, CharSet &setik2) {
    return Size(setik1) < Size(setik2);
}

bool operator>=(CharSet &setik1, CharSet &setik2) {
    return Size(setik1) >= Size(setik2);
}

bool operator<=(CharSet &setik1, CharSet &setik2) {
    return Size(setik1) <= Size(setik2);
}

CharSet& CharSet::operator+=(CharSet &setik) {
    char* c = setik.ToChar();
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx < 0){
            addMapping((unsigned char)c[i]);
            idx = mappingSize - 1;
        }
        setBit(idx);
        i = i + 1;
    }
    return *this;
}

CharSet& CharSet::operator+=(const char *c) {
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx < 0){
            addMapping((unsigned char)c[i]);
            idx = mappingSize - 1;
        }
        setBit(idx);
        i = i + 1;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CharSet& set) {
    os << "{";
    bool first = true;
    for (int i = 0; i < set.mappingSize; ++i) {
        unsigned char c = set.mapping[i];
        if (set.getBit(set.mapChar(c))) {
            if (!first)
                os << ", ";
            os << c;
            first = false;
        }
    }
    os << "}";
    return os;
}

CharSet& CharSet::operator-=(const char *c) {
    int i = 0;
    while(c[i] != 0){
        int idx = mapChar((unsigned char)c[i]);
        if(idx < 0){
            addMapping((unsigned char)c[i]);
            idx = mappingSize - 1;
        }
        clrBit(idx);
        i = i + 1;
    }
    return *this;
}


void print(CharSet &setik){
    int i = 0;
    while(i < setik.mappingSize){
        if(setik.getBit(i)){
            std::cout << setik.mapping[i] << ' ';
        }
        i = i + 1;
    }
    std::cout << '\n';
    return;
}

void CharSet::print() const{
    int i = 0;
    while(i < mappingSize){
        if(getBit(i)){
            std::cout << mapping[i] << ' ';
        }
        i = i + 1;
    }
    std::cout << '\n';
    return;
}
//defense
CharSet operator/(CharSet &setik1, CharSet &setik2) {
    CharSet result("");

    char* a = setik1.ToChar();
    char* b = setik2.ToChar();

    for (int i = 0; a[i] != 0; ++i) {
        unsigned char ch = (unsigned char)a[i];
        if (!inSet(setik2, ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }

    for (int i = 0; b[i] != 0; ++i) {
        unsigned char ch = (unsigned char)b[i];
        if (!inSet(setik1, ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }

    return result;
}


