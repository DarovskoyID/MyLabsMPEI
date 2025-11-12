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
    if (this == &other)
        return *this;

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


CharSet CharSet::operator+(CharSet &setik) {
    char* c = setik.ToChar();
    CharSet t(*this);
    int i = 0;
    while(c[i] != 0){
        int idx = t.mapChar((unsigned char)c[i]);
        if(idx < 0){
            t.addMapping((unsigned char)c[i]);
            idx = t.mappingSize - 1;
        }
        if(this->inSet(c[i]) || setik.inSet(c[i]))
            t.setBit(idx);
        i = i + 1;
    }
    return t;
}


CharSet CharSet::operator-(CharSet &setik) {
    CharSet result("");
    char* c = this->ToChar();
    for (int i = 0; c[i] != 0; ++i) {
        unsigned char ch = (unsigned char)c[i];
        if (this->inSet(ch) && !setik.inSet(ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }
    return result;
}

CharSet CharSet::operator*(CharSet &setik) {
    CharSet result("");
    char* c = this->ToChar();
    for (int i = 0; c[i] != 0; ++i) {
        unsigned char ch = (unsigned char)c[i];
        if (this->inSet(ch) && setik.inSet(ch)) {
            result.addMapping(ch);
            result.setBit(result.mapChar(ch));
        }
    }
    return result;
}


bool CharSet::operator>(CharSet &setik) {
    return this->Size() > setik.Size();
}

bool CharSet::operator<(CharSet &setik) {
    return this->Size() < setik.Size();
}

bool CharSet::operator>=(CharSet &setik) {
    return this->Size() >= setik.Size();
}

bool CharSet::operator<=(CharSet &setik) {
    return this->Size() <= setik.Size();
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

std::ostream& CharSet::operator<<(std::ostream& os) const {
    os << "{";
    int i = 0;
    while(i < mappingSize){
        if(getBit(i)){
            os << mapping[i] << ' ';
        }
        i = i + 1;
    }
    os << "}";
    return os;
}

CharSet& CharSet::operator!(){
    int i = 0;
    while(i < mappingSize){
        if(getBit(i)){
            clrBit(i);
        } else{
            setBit(i);
        }
        i = i + 1;
    }
    return *this;
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
