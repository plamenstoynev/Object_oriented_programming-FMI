#include "EmptySet.h"

bool EmptySet::member(unsigned int num) const {
    return false;
}

Set* EmptySet::virtualCopy() const {
    EmptySet* obj = new EmptySet();
    return obj;
}
