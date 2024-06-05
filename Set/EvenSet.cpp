#include "EvenSet.h"

bool EvenSet::member(unsigned int x) const {
    return x % 2 == 0;
}

Set* EvenSet::virtualCopy() const {
    EvenSet* set = new EvenSet(*this);
    return set;
}