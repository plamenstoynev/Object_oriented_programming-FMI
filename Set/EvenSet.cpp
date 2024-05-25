#include "EvenSet.h"

bool EvenSet::member(unsigned int num) const {
    return num % 2 ==0;
}

Set* EvenSet::virtualCopy() const {
    EvenSet* obj = new EvenSet();
    return obj;
}