#include "Singleton.h"
Singleton::Singleton(unsigned int num){
    this->num = num;
}

Set* Singleton::virtualCopy() const {
    return new Singleton(this->num);
}

bool Singleton::member(unsigned int num) const {
    return num == this->num;
}